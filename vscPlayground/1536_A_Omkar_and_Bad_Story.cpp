/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-08 14:01:32
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
      bool f = false;
      for (int i = 1; i <= n; i++) {
         int x = 0;
         cin >> x;
         if (x < 0) {
            f = true;
         }
      }
      if (f) cout << "NO\n";
      else {
         cout << "YES\n";
         cout << 101 << '\n';
         for (int i = 0; i <= 100; i++) {
            cout << i << ' ';
         }
         cout << '\n';
      }
   }
   
   return 0;
}
/*

*/