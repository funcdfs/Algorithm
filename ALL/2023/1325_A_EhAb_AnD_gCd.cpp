/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-22 16:32:33
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
      // gcd(a, b) + lcm(a, b) == x
      int x = 0;
      cin >> x;
      cout << x - 1 << ' ' << 1 << '\n';
   }
   
   
   return 0;
}
/*

*/