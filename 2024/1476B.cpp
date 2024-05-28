/**
 * name: B. Inflation
 * link: https://codeforces.com/contest/1476/problem/B
 * time: 2024/5/27 10:35:05 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto solve(int _case) -> void {
   dbg(_case);

   int n = 0, k = 0;
   cin >> n >> k;
   vector<int> p(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> p[i];
   }

   vector<int64_t> preSum(n + 1, 0);
   for (int i = 1; i <= n; i++) {
      preSum[i] = preSum[i - 1] + p[i - 1];
   }

   int need = 0;
   for (int i = 0; i <= n; i += 2) {
      if (p[i] * 100 > preSum[i - 1] * k)
         need = max(need, (p[i] * 100 - preSum[i - 1] * k + k - 1) / k);
   }

   return;
}

auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int TT = 0;
   cin >> TT;
   for (int _case = 1; _case <= TT; _case++) {
      solve(_case);
   }

   return 0;
}
/*

*/