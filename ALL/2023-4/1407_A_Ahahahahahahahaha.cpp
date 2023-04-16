/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-13 20:26:12
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
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) cin >> a[i];
      int zeroCnt = count(a.begin(), a.end(), 0);
      if (zeroCnt >= n / 2) {
         cout << n / 2 << '\n';
         for (int i = 0; i < n / 2; i++) {
            cout << 0 << " \n"[i == n / 2 - 1];
         }
      } else {
         int ans = 0;
         if (n / 2 % 2 == 1) {
            ans = n / 2 + 1;
         } else {
            ans = n / 2;
         }
         cout << ans << '\n';
         for (int i = 1; i <= ans; i++) {
            cout << 1 << " \n"[i == ans];
         }
      }
   }

   return 0;
}
/*

*/