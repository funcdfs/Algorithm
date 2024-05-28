// https://github.com/fengwei2002, 2022.12.19 16:08:22
// https://codeforces.com/contest/476/problem/B
// 476B. Dreamoon and WiFi, Codeforces - Codeforces Round #272 (Div. 2)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   string s1 = "", s2 = "";
   cin >> s1 >> s2;

   int pos = count(s1.begin(), s1.end(), '+') - count(s1.begin(), s1.end(), '-');
   double ans = 0.0;

   function<void(int, int, double)> dfs = [&](int id, int p, double odds) -> void {
      if (id == (int)s1.size()) {
         if (p == pos) {
            ans += odds;
         }
         return;
      }
      if (s2[id] == '-') {
         dfs(id + 1, p - 1, odds);
      } else if (s2[id] == '+') {
         dfs(id + 1, p + 1, odds);
      } else {
         dfs(id + 1, p + 1, odds / 2.0);
         dfs(id + 1, p - 1, odds / 2.0);
      }
   };
   
   dfs(0, 0, (double)1);

   cout << fixed << setprecision(20);
   cout << ans << '\n';

   return 0;
}

/*

476B加号减号问号到达正确目的地的概率

*/
