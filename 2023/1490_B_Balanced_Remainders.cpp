/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-05 01:28:27
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
      for(int i = 0; i < n; i++) {
         cin >> a[i];
      }
      // every operation, you can choose an element, add append 1 to it,
      // the minmum operation count to make all elements mod 3, (0, 1, 2), equal;
      vector<int> c(3, 0);
      for (int i = 0; i < n; i++) {
         c[a[i] % 3] += 1;
      }
      int ans = 0;
      while (true) {
         bool ok = true;
         for (int i = 0; i < 3; i++) {
            if (c[i] > n / 3) {
               ok = false;
               ans += c[i] - n / 3;
               c[(i + 1) % 3] += c[i] - n / 3;
               c[i] = n / 3;
            }
         }
         if (ok) break;
      }
      cout << ans << '\n';
   }
   

   return 0;
}