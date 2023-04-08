/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-05 16:50:59
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
      // i divides p[i]
      vector<int> a(n, 0);
      iota(a.begin(), a.end(), 1);
      rotate(a.begin(), a.begin() + 1, a.end());
      for (int i = 0; i < n; i++) {
         cout << a[i] << " \n"[i == n -1];
      }
   }
   
   return 0;
}
/*

*/