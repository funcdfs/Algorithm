/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-06 14:42:00
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
      vector<int> a(2 * n, 0);
      for (int i = 0; i < 2 * n; i++) cin >> a[i];
      // find a array b
      // b[i] != (b[i - 1] + b[i + 1]) / 2
      // b[0] == b[2n] and b[2n + 1] == b[1]
      sort(a.begin(), a.end(), [](int x, int y) {
         return x < y;
      });
      vector<int> b((int)a.size(), 0);
      int idx = 0;
      for (int i = 0; i < (int)a.size(); i += 2) {
         b[i] = a[idx];
         idx += 1;
      }
      for (int i = 1; i < (int)a.size(); i += 2) {
         b[i] = a[idx];
         idx += 1;
      }
      for (int i = 0; i < (int)b.size(); i++) {
         cout << b[i] << " \n"[i == (int)b.size() - 1];
      }

      for (int i = 1; i + 1 < (int)b.size(); i++) {
         if (b[i] == (b[i - 1] + b[i + 1]) / 2) {
            dbg("ERROR", a, b);
         }
      }
   }
   
   return 0;
}
/*

*/