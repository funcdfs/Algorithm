/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-06 12:52:23
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
      int n = 0, m = 0;
      cin >> n >> m;
      int ans = n + m - 2 + min(n, m);
      if (n == 1 and m == 1) {
         ans = 0;
      }
      cout << ans << '\n';
   }
   
   return 0;
}
/*

*/