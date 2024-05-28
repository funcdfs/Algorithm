// https://github.com/fengwei2002, 2023.02.17-21:37:24
// https://codeforces.com/contest/363/problem/B
// 363B. Fence, Codeforces - Codeforces Round #211 (Div. 2)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, k = 0;
   cin >> n >> k;
   
   vector<int> h(n, 0);
   for (int i = 0; i < n; i++) cin >> h[i];
   
   vector<int> preSum(n + 1, 0);
   for (int i = 1; i <= n; i++) {
      preSum[i] = preSum[i - 1] + h[i - 1];
   }
   dbg(h);
   dbg(preSum);
   
   int minVal = numeric_limits<int32_t>::max();
   int idx = 0;
   for (int i = 0; i <= n; i++) {
      if (i + k > n) {
         break;
      }
      int sum = preSum[i + k] - preSum[i];
      dbg(sum, i + k, i);
      if (sum < minVal) {
         idx = i;
         minVal = sum;
      }
   }
   
   cout << idx + 1 << '\n';
   
   return 0;
}

/*

363B栅栏



*/