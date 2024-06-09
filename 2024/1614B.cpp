/**
 * name: B. Divan and a New Project
 * link: https://codeforces.com/contest/1614/problem/B
 * time: 2024/6/8 23:23:16 https://github.com/funcdfs
 **/

#pragma region github_funcdfs
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
#pragma endregion github_funcdfs

auto solve(int _case) -> void {
   dbg(_case);

   int n = 0;
   cin >> n;
   vector<pair<int, int>> a(n);
   for (int i = 0; i < n; i++) {
      cin >> a[i].first;
      a[i].second = i + 1;
   }
   sort(a.begin(), a.end(), [&](auto& x, auto& y) {
      return x.first > y.first;
   });
   int l = -1, r = 1;
   vector<int> x(n + 1, 0);
   x[0] = 0;
   int64_t ans = 0;
   for (int i = 0; i < n; i++) {
      int id = a[i].second;
      if (r == -l) {
         x[id] = l;
         l -= 1;
      } else {
         x[id] = r;
         r += 1;
      }
      ans += (int64_t)abs(x[id]) * (int64_t)a[i].first;
   }
   cout << ans * 2 << endl;
   for (int i = 0; i <= n; i++) {
      cout << x[i] << " \n"[i == n];
   }
   return;
}

/*
第 i 个建筑访问 a[i] 次，每次访问需要花费 2 x[x0 - xi] 的时间来走路。xi 表示第 i
个建筑的位置。 求出最少需要走多远，以及一个具体的 x 数组。
*/

#pragma region main func
auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
   int testCaseCnt = 0;
   cin >> testCaseCnt;
   for (int _case = 1; _case <= testCaseCnt; _case++) {
      solve(_case);
   }
   return 0;
}
#pragma endregion main func
