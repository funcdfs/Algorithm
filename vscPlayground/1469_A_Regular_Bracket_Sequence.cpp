/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-05 01:14:17
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
      string s = "";
      cin >> s;
      if ((int)s.size() % 2 == 1 || s.front() == ')' || s.back() == '(') {
         cout << "NO\n";
      } else {
         cout << "YES\n";
         // (?)? is yes, not no (())
         // only have one ( and one ) so the problem is simplify
      }
   }
   
   return 0;
}