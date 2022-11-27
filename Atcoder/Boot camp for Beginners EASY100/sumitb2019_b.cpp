// LINK: https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_b
// NAME: B - Tax Rate, AtCoder - Sumitomo Mitsui Trust Bank Programming Contest 2019
// CODE: https://github.com/fengwei2002, 2022.11.22-20:49:18, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0;
   cin >> n;

   int ans = -1;
   for (int i = 1; i <= n; i++) {
      if ((int)(i * 1.08) == n) {
         ans = i;
         break;
      }
   }
   if (ans != -1) {
      cout << ans << '\n';
   } else {
      cout << ":(\n";
   }

   return 0;
}

/*



*/