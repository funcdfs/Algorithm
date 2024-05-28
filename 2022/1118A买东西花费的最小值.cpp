// LINK: https://codeforces.com/contest/1118/problem/A
// NAME: 1118A. Water Buying, Codeforces - Codeforces Round #540 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.12-17:37:13, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

#define int int64_t

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      int n = 0, a = 0, b = 0;
      cin >> n >> a >> b;
      b = min(a * 2, b);
      cout << n / 2 * b + n % 2 * a << '\n';
   }
   
   return 0;
}

auto tle_main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      int n = 0, a = 0, b = 0;
      cin >> n >> a >> b;
      dbg(n, a, b);
      vector<int> f(n + 1, numeric_limits<int32_t>::max());
      f[0] = 0;
      for (int i = 1; i <= n; i++) {
         f[i] = min(f[i - 1] + a, f[i]);
         if (i - 2 > 0) {
            f[i] = min(f[i - 2] + b, f[i]);
         }
      }
      cout << f[n] << '\n';
   }
   
   return 0;
}

/*

1118A买东西花费的最小值

*/