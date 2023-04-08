/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 15:19:18
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
      int n = 0, l = 0, r = 0, k =0;
      cin >> n >> l >> r >> k;
      vector<int> a(0, 0);
      a.reserve(n);
      for (int i = 0, x; i < n; i++) {
         cin >> x;
         if (l <= x and x <= r) {
            a.push_back(x);
         }
      }
      sort(a.begin(), a.end());
      int ans = 0;
      while (ans < (int)a.size() and a[ans] <= k) {
         k -= a[ans];
         ans += 1;
      }
      cout << ans << '\n';
   }
   
   return 0;
}
/*

*/