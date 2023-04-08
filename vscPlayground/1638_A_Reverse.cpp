/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-08 11:03:42
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
      // exactly reverse once a sub segment in the array
      // to make the permutation better
      int idx = 0;
      vector<int> standard(n, 0);
      iota(standard.begin(), standard.end(), 1);
      while (idx < n and a[idx] == standard[idx]) idx += 1;
      // the first position to reverse
      int minVal = n + 2, minPos = idx;
      for (int i = idx; i < n; i++) {
         if (a[i] < minVal) {
            minVal = a[i];
            minPos = i;
         }
      }
      dbg(a, idx);
      dbg(minVal, minPos);
      if (minVal == n + 2) {
         for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
         }
      } else {
         dbg("HI");
         dbg(a, idx, minPos);
         reverse(a.begin() + idx, a.begin() + minPos + 1);
         dbg(a);
         for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
         }
      }
   }

   return 0;
}
/*

*/