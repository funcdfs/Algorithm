/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 18:21:15
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
   
   int n = 0;
   cin >> n;
   string s = "";
   cin >> s;
   bool ok = true;
   for (int i = 1; i + 1 < n; i++) {
      if (s[i] != s[i - 1] and s[i] != s[i + 1]) {
         // do nothing
      } else {
         ok = false;
         break;
      }
   }
   if (ok) {
      cout << "Yes\n";
   } else {
      cout << "No\n";
   }
   
   return 0;
}
/*

*/