/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 13:37:39
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
   
   auto test = [](string s) -> void {
      string t = s;
      reverse(t.begin(), t.end());
      if (s == t) {
         dbg("true");
      } else {
         dbg(s);
         dbg("false");
      }
      return;
   };
   int tt = 0;
   cin >> tt;
   while (tt--) {
      string s = "";
      cin >> s;
      string t = s;
      reverse(t.begin(), t.end());
      // test(s + t);
      cout << s << t << '\n';
   }
   
   return 0;
}
/*

*/