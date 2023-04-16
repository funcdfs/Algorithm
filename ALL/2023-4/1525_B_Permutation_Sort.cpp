/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-05 18:44:36
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
      if (is_sorted(a.begin(), a.end())) {
         cout << 0 << '\n';
         continue;
      }
      if (a[0] == 1 or a[n - 1] == n) {
         cout << 1 << '\n';
         continue;
      }
      if (a[0] == n and a[n - 1] == 1) {
         cout << 3 << '\n';
      } else {
         cout << 2 << '\n';
      }
   }
   return 0;
}
/*

*/