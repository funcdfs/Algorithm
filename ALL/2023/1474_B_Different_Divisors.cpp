/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-06 23:14:56
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
   
   // give a d, find the smallest positive integer a, such that 
   // a has at least 4 divisors
   // difference between any two divisors of a is at least d
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int d = 0;
      cin >> d;
      // cout << 1 << ' ' << 1 + d << ' ' << 1 +d + d << ' ' << 
      cout << (int64_t)(1 + d) * (1 + d + d) << '\n';
   }
   
   return 0;
}