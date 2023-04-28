/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-08 10:13:33
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
      // construct a array, that all element not equal to zero
      if (n == 1 or n == 3) {
         cout << "NO\n";
      } else {
         cout << "YES\n";
         if (n % 2) {
            int k = n / 2;
            for (int i = 0; i < k; i++) {
               cout << k - 1 << ' ' << -k << ' ';
            }
            cout << k - 1 << '\n';
         } else {
            for (int i = 0; i < n / 2; i++) {
               cout << -1 << ' ' << 1 << ' ';
            }
            cout << '\n';
         }
      }
   }
   
   return 0;
}
/*

*/