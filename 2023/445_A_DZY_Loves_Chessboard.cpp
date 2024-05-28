/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-09 14:22:54
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
   
   int n = 0, m = 0;
   cin >> n >> m;
   char s;
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> s;
         if (s == '.') {
            if ((i + j) % 2) {
               s = 'W';
            } else {
               s = 'B';
            }
         }
         cout << s;
      }
      cout << '\n';
   }
   
   return 0;
}
/*

*/