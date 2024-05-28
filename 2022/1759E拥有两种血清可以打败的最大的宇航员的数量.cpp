// LINK: https://codeforces.com/contest/1759/problem/E
// NAME: 1759E. The Humanoid, Codeforces - Codeforces Round  #834 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.18-18:51:45, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0, h = 0;
      cin >> n >> h;
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) {
         cin >> a[i];
      }
      sort(a.begin(), a.end());
      
      function<int(int, int64_t, int, int)> solve = [&](int i, int64_t h, int s2, int s3) -> int {
         if (i == n) return 0;
         if (a[i] < h) {
            return solve(i + 1, h + (a[i] / 2), s2, s3) + 1;
         }
         int ans1 = (s2 > 0 ? solve(i, h * 2, s2 - 1, s3) : 0);
         int ans2 = (s3 > 0 ? solve(i, h * 3, s2, s3 - 1) : 0);
         return max(ans1, ans2);
      };
      
      cout << solve(0, h, 2, 1) << '\n';
   }
   
   return 0;
}

/*

1759E拥有两种血清可以打败的最大的宇航员的数量


可以乘 2 两次
乘 3 一次

求最大的可以打败的数量

递归
*/