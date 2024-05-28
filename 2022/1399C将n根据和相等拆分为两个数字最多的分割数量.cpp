// https://github.com/fengwei2002, 2022.12.19 17:03:46
// https://codeforces.com/contest/1399/problem/C
// 1399C. Boats Competition, Codeforces - Codeforces Round #661 (Div. 3)

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
      int n = 0;
      cin >> n;
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) cin >> a[i];
      
      // a[i] less than n <= 50 Positive number
      unordered_map<int, int> cnt;
      for (auto& x : a) cnt[x] += 1;
      
      int ans = 0;
      for (int v = 2; v <= 2 * n; v++) {
         int cur = 0;
         for (int i = 1; 2 * i <= v; i++) {
            if (v - i > n) continue;
            if (2 * i == v) {
               cur += cnt[i] / 2;
            } else {
               cur += min(cnt[i], cnt[v - i]);
            }
         }
         ans = max(ans, cur);
      }
      cout << ans << '\n';
   }
   
   return 0;
}

/*


1399C将n根据和相等拆分为两个数字最多的分割数量


*/