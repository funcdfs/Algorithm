/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-09 20:37:01
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
      int n = 0, k = 0;
      cin >> n >> k;
      // Output n - 2 a's and 2 b's.
      // print the k-th string from the list
      for (int i = n - 1; i >= 0; i--) {
         if (k > n - i) {
            k = k - (n - i);
         } else {
            string ans = string(n, 'a');
            ans[i - 1] = 'b';
            ans[n - k] = 'b';
            cout << ans << '\n';
            break;
         }
      }
   }
   
   return 0;
}
/*

*/