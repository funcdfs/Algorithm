/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-13 20:10:03
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
      vector<int> b(n + 2, 0);
      for (int i = 0; i < n + 2; i++) cin >> b[i];
      // a[0 \to n], sum(a), random number
      // give array b, find origin array a
      sort(b.begin(), b.end());
      int64_t sum1 = accumulate(b.begin(), b.begin() + n, (int64_t)0);
      if (sum1 == b.back() or sum1 == b.rbegin()[1]) {
         for (int i = 0; i < n; i++) {
            cout << b[i] << " \n"[i == n - 1];
         }
         continue;
      }
      int64_t sum2 = sum1 + b.rbegin()[1];
      int idx = -1;
      for (int i = 0; i < n; i++) {
         if (sum2 - b[i] == b.back()) {
            idx = i;
            break;
         }
      }
      if (idx == -1) {
         cout << -1 << '\n';
         continue;
      } else {
         for (int i = 0; i < n + 1; i++) {
            if (i == idx) continue;
            cout << b[i] << " \n"[i == n];
         }
      }
   }
   
   return 0;
}
/*

*/