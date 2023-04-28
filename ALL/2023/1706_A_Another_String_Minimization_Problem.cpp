/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-07 13:13:20
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
      int n = 0, m = 0;
      cin >> n >> m;
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) cin >> a[i];
      // a consisting of integers between 1 and m
      // s, consisting of m 'B'
      string s = string(m, 'B');

      for (int i = 0; i < n; i++) {
         int x = a[i];
         int y = (m + 1 - a[i]);
         x--, y--;
         if (x > y) swap(x, y);
         if (x <= y and s[x] == 'B') {
            s[x] = 'A';
         } else {
            s[y] = 'A';
         }
      }
      cout << s << '\n';
   }
   
   return 0;
}
/*

*/