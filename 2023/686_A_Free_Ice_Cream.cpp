/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-03 16:04:49
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
#define int int64_t
auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, x = 0;
   cin >> n >> x;
   int ans = 0;
   for (int T = 0; T < n; T++) {
      string s;
      cin >> s;
      int d = 0;
      cin >> d;
      if (s == "+") {
         x += d;
      } else {
         if (x >= d) {
            x -= d;
         } else {
            ans += 1;
         }
      }
   }
   cout << x << ' ';
   cout << ans << '\n';
   return 0;
}
/*

*/