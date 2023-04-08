/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-06 13:15:19
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
      string t = "";
      cin >> t;
      // t is the subString of s
      int cnt1 = count(t.begin(), t.end(), '1');
      int cnt2 = count(t.begin(), t.end(), '0');
      if (cnt1 == (int)t.size()) {
         cout << t << '\n';
      } else if (cnt2 == (int)t.size()) {
         cout << t << '\n';
      } else {
         // normal string
         string s = "";
         if (cnt1 >= cnt2) {
            for (int i = 0; i < (int)t.size() - 1; i++) {
               cout << "10";
            }
            cout << 1 << '\n';
         } else {
            for (int i = 0; i < (int)t.size() - 1; i++) {
               cout << "01";
            }
            cout << 0 << '\n';
         }
      }
   }

   return 0;
}
/*

*/