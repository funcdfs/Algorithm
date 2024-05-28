/**
 * name: C. Little Girl and Maximum Sum
 * link: https://codeforces.com/contest/276/problem/C
 * time: 2024/5/25 22:17:27 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
#define int long long

auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0, q = 0;
   cin >> n >> q;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];
   dbg(n, q, a);

   unordered_map<int, int> hs;
   vector<pair<int, int>> query;
   while (q--) {
      int l = 0, r = 0;
      cin >> l >> r;
      query.push_back({l, r});
      l -= 1, r -= 1;
      hs[l] += 1;
      hs[r + 1] -= 1;
   }
   // 1 2 
   //   2 3 
   // 1 2 3 
   // 2 3 2 
   for (int i = 0; i < n; i++) {
      hs[i] += hs[i - 1];
   }

   vector<int> freq(n, 0);
   for (auto& [_, v] : hs) {
      freq.push_back(v);
   }

   ranges::sort(freq, [&](auto& xx, auto& yy) {
      return xx > yy;
   });
   ranges::sort(a, [&](auto& xx, auto& yy) {
      return xx > yy;
   });

   while (freq.size() < n) {
      freq.push_back(0);
   }

   int ans = 0;
   for (int i = 0; i < n; i++) {
      ans += freq[i] * a[i];
   }

   cout << ans << endl;

   return 0;
}
/*

*/