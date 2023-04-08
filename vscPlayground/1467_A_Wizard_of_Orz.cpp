/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-05 19:24:35
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
   for (cin >> tt; tt; tt -= 1) {
      int n = 0;
      cin >> n;
      string s = "9890123456789";
      if (n > (int)s.size()) {
         cout << s;
         n -= (int)s.size();
         int init = 0;
         for (int i = 0; i < n; i++) {
            cout << init;
            init += 1;
            if (init == 10) {
               init = 0;
            }
         }
         cout << '\n';
      } else {
         cout << s.substr(0, n) << '\n';
      }
   }
   
   return 0;
}
/*

*/