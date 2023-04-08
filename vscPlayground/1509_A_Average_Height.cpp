/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-05 17:33:03
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      vector<int> a(n, 0);
      for(int i = 0; i < n; i++) {
         cin >> a[i];
      }
      // 两个相邻数字的平均数是整数的最大 pair 数量
      vector<int> odd(0, 0), even(0, 0);
      for (auto& x : a) {
         if (x % 2 == 0) {
            even.push_back(x);
         } else {
            odd.push_back(x);
         }
      }
      for (auto x : even) cout << x << ' ';
      for (auto x : odd) cout << x << ' ';
      cout << '\n';
   }
   
   
   return 0;
}
/*

*/