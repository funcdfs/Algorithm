/**
 * name: B. Nastya and Door
 * link: https://codeforces.com/contest/1341/problem/B
 * time: 2024/5/28 18:12:02 https://github.com/funcdfs
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
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];
   
   vector<int> sum(n, 0);
   for (int i = 1; i + 1 < n; i++) {
      sum[i + 1] = sum[i - 1];
      if (a[i - 1] < a[i] and a[i + 1] < a[i]) {
         sum[i + 1] += 1;
      }
   }
   sum.push_back(sum[n - 1]);
   int ans = 0, l = 0;
   for (int i = 0; i + k <= n; i++) {
      auto s = sum[i + k] - sum[i];
      if (sum[i + 1] > sum[i]) {
         s -= 1;
      }
      if (sum[i + k] > sum[i + k - 1]) {
         s -= 1;
      }
      if (s > ans) {
         ans = s;
         l = i;
      }
   }

   cout << ans + 1 << ' ' << l + 1 << '\n';
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