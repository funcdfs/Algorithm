/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-08 11:38:40
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
      // find two permutation that with the same fingerprint
      // [1, n], [2, n - 1]
      for (int i = n - 1; i >= 0; i--) {
         cout << a[i] << " \n"[i == 0];
      }
   }
   
   return 0;
}
/*

*/