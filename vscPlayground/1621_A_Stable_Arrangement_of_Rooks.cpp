/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-06 14:09:50
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
      int n = 0, k = 0;
      cin >> n >> k;
      if ((n + 1) / 2 < k) {
         cout << -1 << '\n';
      } else {
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               cout << (i == j and i % 2 == 0 and i < 2 * k ? 'R' : '.');
            }
            cout << '\n';
         }
      }
   }
   
   return 0;
}
/*

*/