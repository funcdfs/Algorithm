/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-08 11:56:53
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
      // for each case print k integers [a1, a2, ... ak]
      if (n & 1) {
         cout << (n - 1) / 2 << ' ';
         cout << (n - 1) / 2 << ' ';
         cout << 1 << '\n';
      } else if (n & 2) {
         cout << (n - 2) / 2 << " " << (n - 2) / 2 << " " << 2 << "\n";
      } else {
         cout << (n / 2) << ' ' << n / 4 << ' ' << n / 4 << '\n';
      }
   }
   
   return 0;
}
/*

*/