// https://github.com/fengwei2002, 2023.02.19-17:26:54
// https://codeforces.com/contest/279/problem/B
// 279B. Books, Codeforces - Codeforces Round #171 (Div. 2)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   int n = 0, m = 0;
   cin >> n >> m;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];
   vector<int64_t> preSum(n + 1, 0);
   for (int i = 1; i <= n; i++) {
      preSum[i] = preSum[i - 1] + a[i - 1];
   }
   dbg(preSum);
   int ans = 0;
   // for (int i = 0; i < n; i++) {
   for (int i = 0; i <= n; i++) {
      int cur = upper_bound(preSum.begin(), preSum.end(), preSum[i] + m) - preSum.begin() - i - 1;
      ans = max(ans, cur);
   }
   cout << ans << '\n';
   return 0;
}

/*
279B可以看完的书的数量




*/