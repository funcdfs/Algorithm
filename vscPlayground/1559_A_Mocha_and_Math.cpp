/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-05 17:20:14
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
      // 所有的规定区间然后取并值的话，堆最大值最小化都是有益的
      // 例如 2，1，所有数字的与最后都会计算一次
      // 所以最终所有的数字都会被 & 一次
      int ans = a[0];
      for (int i = 1; i < n; i++) {
         ans &= a[i];
      }
      cout << ans << '\n';
   }
   
   return 0;
}
/*

*/