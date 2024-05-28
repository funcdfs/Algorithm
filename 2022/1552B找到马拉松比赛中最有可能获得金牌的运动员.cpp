// LINK: https://codeforces.com/contest/1552/problem/B
// NAME: 1552B. Running for Gold, Codeforces - Codeforces Global Round 15
// CODE: https://github.com/fengwei2002, 2022.10.24-21:49:45, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      vector<vector<int>> r(n, vector<int>(5, 0));

      function<void()> solve = [&]() {
         int u = 0;
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < 5; j++) {
               cin >> r[i][j];
            }
            if (i == 0) continue;
            int x = 0;
            for (int j = 0; j < 5; j++) {
               x += (r[i][j] < r[u][j]);
            }
            if (x >= 3) {
               u = i;
            }
         }
         // 等价于求一遍 max function

         for (int i = 0; i < n; i++) {
            if (u == i) continue;
            int x = 0;
            for (int j = 0; j < 5; j++) {
               x += r[i][j] < r[u][j];
            }
            if (x >= 3) {
               u = -1;
               break;
            }
         }
         // 如果不存在第二个 竞争者，那么最后就是第一个人
         
         if (u < 0) {
            cout << -1 << '\n';
         } else {
            cout << u + 1 << '\n';
         }
      };
      solve();
   }

   return 0;
}

/*

1552B找到马拉松比赛中最有可能获得金牌的运动员


预判规则：
   如果某一个选手能够获得金牌，那么他可以战胜其他所有的选手
   战胜一个选手意味着，至少在 3 个比赛中战胜了一个选手


因为 3/5 就是赢家，所以如果 j 是由于 i 的话，i 不可能优于 j 了
枚举所有的 c_n^2 O(n^2) TLE
 
观察到，最多只会存在一个玩家最有可能得到最后的金牌
   假设存在两个玩家可以得到金牌，那么 A 就要比 B 大 3 次，同时 B 也要比 A 大三次
   就会出现矛盾


*/