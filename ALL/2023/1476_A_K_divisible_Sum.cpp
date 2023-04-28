/**
 * Code: https://github.com/fengwei2002
 * Time: 2023-03-03 01:39
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

   // n 个整数，和可以被 k 整除，a 的最大值越小越好
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0, k = 0;
      cin >> n >> k;
      if (n >= k) {
         if (n % k == 0) {
            cout << 1 << '\n';
         } else {
            cout << 2 << '\n';
         }
      } else {
         if (k % n == 0) {
            cout << k / n << '\n';
         } else {
            cout << k / n + 1 << '\n';
         }
      }
   }

   return 0;
}

/*



*/
