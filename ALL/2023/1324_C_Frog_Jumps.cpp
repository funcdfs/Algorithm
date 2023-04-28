/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-09 14:25:30
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
      vector<int> pos;
      pos.push_back(0);
      for (int i = 0; i < (int)s.size(); i++) {
         if (s[i] == 'R') {
            pos.push_back(i + 1);
         }
      }
      pos.push_back((int)s.size() + 1);
      int ans = 0;
      for (int i = 0; i < (int)pos.size() - 1; i++) {
         ans = max(ans, pos[i + 1] - pos[i]);
      }
      cout << ans << '\n';
   }
   
   return 0;
}
/*

*/