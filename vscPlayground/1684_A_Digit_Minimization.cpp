/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 16:15:39
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
      if ((int)s.size() == 2) {
         cout << s[1] << '\n';
      } else {
         vector<int> a(0, 0);
         for (int i = 0; i < (int)s.size(); i++) {
            a.push_back(s[i] - '0');
         }
         int minVal = *min_element(a.begin(), a.end());
         cout << minVal << '\n';
      }
   }
   
   return 0;
}
/*

*/