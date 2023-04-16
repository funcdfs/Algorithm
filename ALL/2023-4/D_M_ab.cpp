/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 19:04:23
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

#define INF (int64_t)2e18

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int64_t n, m, x, ans = INF;
   cin >> n >> m;
   for (int64_t i = 1; i <= n; i++) {
      x = (m + i - 1) / i;
      if (x <= n) {
         ans = min(ans, i * x);
      }
      if (i > x) break;
   }
   if (ans == INF) cout << -1 << '\n';
   else cout << ans << '\n';
   return 0;
}
/*

*/