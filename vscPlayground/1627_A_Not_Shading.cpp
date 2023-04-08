/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-06 14:14:49
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
      int n = 0, m = 0, r = 0, c = 0;
      cin >> n >> m >> r >> c;
      r -= 1, c -= 1;
      // from other balck to make [r, c] to black
      vector g(n, vector<char>(m, ' '));
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            cin >> g[i][j];
         }
      }
      if (g[r][c] == 'B') {
         cout << 0 << '\n';
         continue;
      }
      bool ok = false;
      for (int i = 0; i < m; i++) {
         if (g[r][i] == 'B') {
            ok = true;
            break;
         }
      }
      for (int i = 0; i < n; i++) {
         if (ok == true) break;
         if (g[i][c] == 'B') {
            ok = true;
            break;
         }
      }
      if (ok) {
         cout << 1 << '\n';
         continue;
      }
      ok = false;
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            if (g[i][j] == 'B') {
               ok = true;
               break;
            }
         }
      }
      if (ok) {
         cout << 2 << '\n';
         continue;
      }
      cout << -1 << '\n';
   }
   
   return 0;
}
/*

*/