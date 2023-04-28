/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-05 17:12:46
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
      // p[i] | p[i + 1] | p[j] >= j - i + 1
      // holds for every pair i and j
      // a subarray's or sum, greater or equal to the length
      for (int i = 0; i < n; i++) {
         cout << i + 1 << " \n"[i == n - 1];
      }
   }
   
   return 0;
}
/*

*/