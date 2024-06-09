/**
 * name: B. Powers of Two
 * link: https://codeforces.com/contest/702/problem/B
 * time: 2024/5/30 11:42:18 https://github.com/funcdfs
 **/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif



auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }

   // ai + aj = 2^x
   map<int, int> cnt;
   int64_t ans = 0;
   for (int i = 0; i < n; i++) {
      auto ai = a[i];
      if (!cnt.empty()) {
         int m = cnt.rbegin()->first;
         for (int64_t x = 2; x <= m + ai; x <<= 1) {
            if (x > ai) {
               ans += cnt[x - ai];
            }
         }
      }
      cnt[a] += 1
   }

   cout << format("{0}\n", ans);
   
   return 0;
}
/*

*/