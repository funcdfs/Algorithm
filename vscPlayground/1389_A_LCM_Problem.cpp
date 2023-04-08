/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 12:08:26
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
      int l = 0, r = 0;
      cin >> l >> r;
      // lcm(x, y) >= l, lcm(x, y) <= r
      if (r < 2 * l) {
         cout << -1 << ' ' << -1 << '\n';
      } else {
         cout << l << ' ' << 2 * l << '\n';
      }
   }
   
   return 0;
}
/*

*/