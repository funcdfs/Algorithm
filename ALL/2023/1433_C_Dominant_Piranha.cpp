/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-05 17:44:12
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
      int maxVal = *max_element(a.begin(), a.end());
      int cnt = count(a.begin(), a.end(), maxVal);
      if (cnt == n) {
         cout << -1 << '\n';
      } else if (cnt == 1) {
         cout << find(a.begin(), a.end(), maxVal) - a.begin() + 1 << '\n';
      } else {
         for (int i = 0; i < n; i++) {
            if (a[i] == maxVal) {
               if (i > 0 and a[i] > a[i - 1]) {
                  cout << i + 1 << '\n';
                  break;
               }
               if (i + 1 < n and a[i] > a[i + 1]) {
                  cout << i + 1 << '\n';
                  break;
               }
            }
         }
      }
   }
   
   return 0;
}
/*

*/