/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 18:23:31
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
   
   vector<string> g(8, "");
   for (int i = 0; i < 8; i++) {
      cin >> g[i];
   }
   
   int n = (int)g.size(), m = (int)g[0].size();
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         if (g[i][j] == '*') {
            dbg(i, j);
            cout << char('a' + j);
            cout << m - i;
            return 0;
         }
      }
   }

   return 0;
}
/*

*/