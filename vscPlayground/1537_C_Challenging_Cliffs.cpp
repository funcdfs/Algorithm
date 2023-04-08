/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-09 00:25:53
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

#define int long long

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      vector<int> h(n, 0);
      for (int i = 0; i < n; i++) cin >> h[i];
      sort(h.begin(), h.end());
      if (n == 2) {
         cout << h[0] << ' ' << h[1] << '\n';
         continue;
      }
      int x = 1; // end position
      for (int i = 2; i < n; i++) {
         if (h[i] - h[i - 1] < h[x] - h[x - 1]) {
            x = i;
         }
      }
      for (int i = x; i < n; i++) {
         cout << h[i] << ' ';
      }
      for (int i = 0; i < x; i++) {
         cout << h[i] << " \n"[i == x - 1];
      }
   }
   
   return 0;
}
/*

*/