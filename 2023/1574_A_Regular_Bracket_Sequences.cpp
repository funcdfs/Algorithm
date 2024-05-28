/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 16:54:22
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
      for (int k = 0; k < n; k++) {
         cout << string(k, '(') + string(k, ')') + string(n - k, '(') + string(n - k, ')');
         cout << '\n';
      }
   }
   
   return 0;
}
/*

*/