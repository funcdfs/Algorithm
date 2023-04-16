/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 12:55:52
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
      int64_t n = 0, m = 0;
      cin >> n >> m;
      int64_t ans = 0;
      ans += (1 + m) * m / 2;
      ans += (m + n * m) * n / 2;
      ans -= m;
      cout << ans << '\n';
   }
   
   return 0;
}
/*

*/