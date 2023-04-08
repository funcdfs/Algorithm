/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-08 10:58:22
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
      string s = "";
      cin >> s;
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) a[i] = s[i] - '0';
      int sum = a[0];
      for (int i = 1; i < n; i++) {
         if (sum == 1) {
            cout << '-';
            sum -= a[i];
         } else {
            cout << '+';
            sum += a[i];
         }
      }
      cout << '\n';
   }
   
   return 0;
}
/*

*/