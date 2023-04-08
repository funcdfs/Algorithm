/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 12:45:40
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
      int n = 0;
      cin >> n;
      string s = "";
      cin >> s;
      cout << [&]() -> int {
         for (int i = 0; i + 1 < n; i++) {
            if (s[i] == 'R' and s[i + 1] == 'L') {
               return 0;
            }
         }
         for (int i = 0; i + 1 < n; i++) {
            if (s[i] == 'L' and s[i + 1] == 'R') {
               return i + 1;
            }
         }
         return -1;
      }() << '\n';
   }
   return 0;
}
/*

*/