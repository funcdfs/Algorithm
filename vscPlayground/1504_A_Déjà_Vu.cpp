/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 16:44:48
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
      int n = (int)s.size();
      auto pos = s.find_first_not_of('a');
      if (pos == string::npos) {
         cout << "NO\n";
         continue;
      }

      for (auto t : {'a' + s, s + 'a'}) {
         if (t != string(t.rbegin(), t.rend())) {
            cout << "YES\n";
            cout << t << '\n';
            break;
         }
      }
   }
   
   return 0;
}
/*

*/