/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-06 13:34:33
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
      // has a value that differs from the value of p[i] by one 
      // have no fixed points
      if (n == 2) {
         cout << "2 1\n";
         continue;
      }
      if (n == 3 or n == 1) {
         cout << -1 << '\n';
         continue;
      } else {
         vector<int> a(n, 0);
         iota(a.begin(), a.end(), 1);
         rotate(a.begin(), a.begin() + 2, a.end());
         for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
         }
         for (int i = 0; i < (int)a.size(); i++) {
            if (a[i] == i + 1) {
               dbg(a, a[i], i);
            }
         }
      }
   }
   
   return 0;
}
/*

*/