/**
 * Code: https://github.com/fengwei2002
 * Time: 2023-03-03 23:15
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int64_t a, b, x, y, n;
      cin >> a >> b >> x >> y >> n;
      // choose a || b and  -= 1
      // value a cannot become less than x
      // value b cannot become less than y
      // find the mini a * b
      n = min(n, a - x + b - y);

      int64_t da = min(a - x, n);
      int64_t ans = (a - da) * (b - (n - da));

      int64_t db = min(b - y, n);
      ans = min(ans, (a - (n - db)) * (b - db));
      cout << ans << '\n';
   }

   return 0;
}

/*



*/
