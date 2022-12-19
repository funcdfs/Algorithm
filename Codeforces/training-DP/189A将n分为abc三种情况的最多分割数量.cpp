// LINK: https://codeforces.com/contest/189/problem/A
// NAME: 189A. Cut Ribbon, Codeforces - Codeforces Round #119 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.12.18-23:24:21, 1000 ms

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
   vector<int> a(3, 0);
   cin >> n;
   for (int i = 0; i < 3; i++) cin >> a[i];
   
   vector f(1e5, (int64_t)-1);
   f[0] = 0;
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j <= n; j++) {
         if (f[j] != -1) {
            f[j + a[i]] = max(f[j + a[i]], f[j] + 1);
         }
      }
   }
   cout << f[n] << '\n';

   return 0;
}

/*

189A将n分为abc三种情况的最多分割数量

*/