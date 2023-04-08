/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-08 10:41:36
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
      // move all value to the end
      // preChoice: select i < j, move a[i] = a[i] - 1, a[j] = a[j] + 1
      //    the all sub array greater than 0
      // make them to a string as possible, than move
      int zeroIdx = 0;
      for (int i = 0; i < n; i++) {
         if (a[i] != 0) {
            zeroIdx = i;
            break;
         }
      }
      int64_t sum = 0;
      int zeroCnt = 0;
      for (int i = zeroIdx; i < n - 1; i++) {
         if (a[i] == 0) zeroCnt += 1;
         sum += a[i];
      }
      if (sum == 0) {
         cout << 0 << '\n';
         continue;
      }
      cout << zeroCnt + sum << '\n';
   }
   
   return 0;
}
/*

*/