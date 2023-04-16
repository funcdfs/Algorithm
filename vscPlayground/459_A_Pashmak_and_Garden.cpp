/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-13 18:55:24
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
   
   int a1, a2, b1, b2, l;
   cin >> a1 >> b1 >> a2 >> b2;
   l = max(abs(a1 - a2), abs(b1 - b2));
   if (a1 == a2) {
      cout << a1 + l << ' ' << b1 << ' ';
      cout << a2 + l << ' ' << b2;
   } else if (b1 == b2) {
      cout << a1 << ' ' << b1 + l << ' ';
      cout << a2 << ' ' << b2 + l;
   } else if (abs(a1 - a2) != abs(b1 - b2)) {
      cout << -1;
   } else {
      cout << a1 << ' ' << b2 << ' ' << a2 << ' ' << b1;
   }
   return 0;
}
/*

*/