/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-22 15:45:37
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
      // i - a[j] != i - a[i]
      sort(a.begin(), a.end(), [](int x, int y) {
         return x > y;
      });
      for (int i = 0; i < (int)a.size(); i++) {
         cout << a[i] << " \n"[i == (int)a.size() - 1];
      }
   }
   return 0;
}
/*

*/