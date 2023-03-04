/**
 * Code: https://github.com/fengwei2002
 * Time: 2023-03-03 23:07
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      // n digits
      // no digit equal to 0
      // s > 0
      // s is not divisible by any of it's digits

      if (n == 1) {
         cout << -1 << '\n';
         continue;
      }
      cout << 2;
      for (int i = 2; i <= n; i++) {
         cout << 3;
      }
      cout << '\n';
   }

   return 0;
}

/*



*/
