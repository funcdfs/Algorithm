/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-03 16:18:05
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
      iota(a.begin(), a.end(), 1);
      if (n % 2) {
         if (n == 3) {
            cout << "3 1 2\n";
         } else {
            cout << "3 1 2\n";
            for (int i = 4; i < n; i += 2) {
               int x = i, y = i + 1;
               cout << y << ' ' << x << ' ';
            }
            cout << '\n';
         }
         continue;
      }
      for (int i = 0; i < (int)a.size(); i += 2) {
         int x = a[i], y = a[i + 1];
         cout << y << ' ' << x << ' ';
      }
      cout << '\n';
   }
   
   return 0;
}
/*

*/