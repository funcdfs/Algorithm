/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-06 15:58:31
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
      int n = 0, k = 0;
      cin >> n >> k;
      if (n < k) {
         cout << k - n << '\n';
      } else {
         cout << (n - k) % 2 << '\n';
      }
   }
   
   return 0;
}
/*

*/