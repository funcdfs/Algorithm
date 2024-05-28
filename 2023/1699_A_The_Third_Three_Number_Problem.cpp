/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-05 19:07:05
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
   for (cin >> tt; tt; tt -= 1) {
      int n = 0;
      cin >> n;
      if (n % 2) {
         cout << -1 << '\n';
      } else {
         cout << n / 2 << ' ' << n / 2 << ' ' << 0 << '\n';
      }
   }
   
   return 0;
}
/*
https://codeforces.com/blog/entry/108560
*/