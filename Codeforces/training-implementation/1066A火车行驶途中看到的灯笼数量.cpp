// LINK: https://codeforces.com/contest/1066/problem/A
// NAME: 1066A. Vova and Train, Codeforces - Codeforces Round #515 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.12-14:46:56, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int ed = 0, v = 0, l = 0, r = 0;
      cin >> ed >> v >> l >> r;
      
      // all - [r, l]
      cout << ed / v  - (r / v - max(l - 1, 0) / v) << '\n';
   }
   
   return 0;
}

/*

1066A火车行驶途中看到的灯笼数量

*/