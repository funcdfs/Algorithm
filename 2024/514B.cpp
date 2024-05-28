/**
 * name: B. Han Solo and Lazer Gun
 * link: https://codeforces.com/contest/514/problem/B
 * time: 2024/5/26 13:53:41 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

struct pair_hash {
   template <class T1, class T2>
   std::size_t operator()(const std::pair<T1, T2>& p) const {
      auto h1 = std::hash<T1>{}(p.first);
      auto h2 = std::hash<T2>{}(p.second);
      return h1 ^ h2;
   }
};
unordered_map<pair<int, int>, int, pair_hash> hs;

auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0, x0 = 0, y0 = 0;
   cin >> n >> x0 >> y0;

   vector<array<int, 2>> e(n);
   for (int i = 0; i < n; i++) {
      cin >> e[i][0] >> e[i][1];
   }

   auto check = [&](int& dx, int& dy) -> void {
      if (dx < 0 and (dy < 0 or dy > 0 or dy == 0)) {
         dx = -dx, dy = -dy;
      } else if (dx == 0 and dy < 0) {
         dx = -dx, dy = -dy;
      }
      // change all dx/dy to part 1 and 4
   };

   for (int i = 0; i < n; i++) {
      int& x1 = e[i][0];
      int& y1 = e[i][1];
      int dx = x1 - x0;
      int dy = y1 - y0;
      check(dx, dy);
      int g = gcd(dx, dy);
      hs[{dy / g, dx / g}] += 1;
   }

   cout << (int)hs.size() << endl;

   return 0;
}
/*

*/