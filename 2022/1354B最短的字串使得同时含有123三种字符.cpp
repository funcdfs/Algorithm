// https://github.com/fengwei2002, 2022.12.19 17:54:07
// https://codeforces.com/contest/1354/problem/B
// 1354B. Ternary String, Codeforces - Educational Codeforces Round 87 (Rated for Div. 2)

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
      string s = "";
      cin >> s;
      int n = (int)s.size();

      vector<int> cnt(3, 0);
      int ans = numeric_limits<int32_t>::max();
      for (int i = 0, j = 0; i < n; i++) {
         cnt[s[i] - '1'] += 1;
         if (cnt[0] && cnt[1] && cnt[2]) {
            while (j < i && cnt[s[j] - '1'] > 1) {
               cnt[s[j] - '1'] -= 1;
               j += 1;
            }
            ans = min(ans, i - j + 1);
         }
      }

      if (ans == numeric_limits<int32_t>::max()) {
         cout << 0 << '\n';
      } else {
         cout << ans << '\n';
      }
   }

   return 0;
}

/*

1354B最短的字串使得同时含有123三种字符



*/