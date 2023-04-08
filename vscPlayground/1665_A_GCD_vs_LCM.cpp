/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 11:55:52
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
      // a + b + c + d == n
      // gcd(a, b) = lcm(c, d)
      // gcd(1, n) = 1, lcm(1, n) = n
      cout << 1 << ' ' << n - 3 << ' ' << 1 << ' ' << 1 << '\n';
   }
   
   return 0;
}
/*

*/