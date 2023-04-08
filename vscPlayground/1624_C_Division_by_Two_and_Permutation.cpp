/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 13:40:49
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
      // replace any element of the array a[i], with a[i] / 2;
      // make array a to becom a permutation of [1, n]
      
      unordered_map<int, int> hs;
      for (int i = 0; i < n; i++) {
         int x = a[i];
         while (x > 0) {
            if (x == 0) break;
            if (x > n or hs.contains(x)) {
               x /= 2;
            } else if (x >= 1 and x <= n) {
               hs[x] = 1;
               break;
            }
         }
      }
      for (auto& [k, v] : hs) {
         dbg(k, v);
      }
      bool ok = true;
      for (int i = 1; i <= n; i++) {
         if (hs.contains(i) == false) {
            ok = false;
            break;
         }
      }
      if (ok == false) {
         cout << "NO\n";
      } else {
         cout << "YES\n";
      }
   }
   
   return 0;
}
/*

*/