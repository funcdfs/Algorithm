// LINK: https://atcoder.jp/contests/abc121/tasks/abc121_b
// NAME: B - Can you solve this?, AtCoder - AtCoder Beginner Contest 121
// CODE: https://github.com/fengwei2002, 2022.11.22-21:03:19, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0, m = 0, C = 0;
   cin >> n >> m >> C;
   vector<int> B(m, 0);
   for (int i = 0; i < m; i++) cin >> B[i];

   vector<vector<int>> A(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> A[i][j];
      }
   }
   int cnt = 0;

   auto cal = [&](vector<int>& a, vector<int>& b) {
      int64_t ans = 0;
      for (int i = 0; i < (int)a.size(); i++) {
         ans += a[i] * b[i];
      }
      if (ans + C > 0) {
         return true;
      }
      return false;
   };

   for (auto& a : A) {
      if (cal(a, B)) {
         cnt++;
      }
   }

   cout << cnt << '\n';

   return 0;
}

/*



*/