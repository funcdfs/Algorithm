// LINK: https://codeforces.com/contest/1759/problem/C
// NAME: 1759C. Thermostat, Codeforces - Codeforces Round  #834 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.17-15:29:01, 1000 ms

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
      int l = 0, r = 0, x = 0;
      cin >> l >> r >> x;
      int a = 0, b = 0;
      cin >> a >> b;
      
      auto solve = [&]() -> int {
         if (a == b) {
            return 0;
         }
         if (abs(a - b) >= x) {
            return 1;
         }
         if (r - max(a, b) >= x or min(a, b) - l >= x) {
            return 2;
         }
         // b -> r -> a
         if (r - b >= x and a - l >= x || r - a >= x and b - l >= x) {
            return 3;
         }
         // a -> l -> r -> b, a -> r -> l -> b
         return -1;
      };
      cout << solve() << '\n';
   }
   
   return 0;
}

/*

1759C调节温度计

*/