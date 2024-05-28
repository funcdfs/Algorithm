/**
 * name: Heaters
 * link: https://www.luogu.com.cn/problem/CF1066B
 * time: 2024/5/19 14:44:29 https://github.com/funcdfs
 **/
#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0, r = 0;
   cin >> n >> r;
   vector<int> a(n, 0);
   for (auto& x : a) cin >> x;

   vector<bool> st(n, false);
   vector<bool> fuck(n, false);
   auto warm = [&](int x) -> void {
      st[x] = true;
      for (int i = max(0, x - r + 1); i <= min(n - 1, x + r - 1); i++) {
         st[i] = true;
      }
   };
   auto close = [&](int x) -> void {
      fill(st.begin(), st.end(), false);
      for (int i = 0; i < n; i++) {
         if (a[i] != 1) continue;
         if (i == x) continue;
         if (fuck[i] == true) continue;
         warm(i);
      }
   };
   for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
         warm(i);
      }
   }

   auto check = [&]() -> bool {
      if (count(st.begin(), st.end(), false)) {
         return false;
      }
      return true;
   };

   if (check() == false) {
      cout << format("-1\n");
      return 0;
   }

   int cnt = (int)count(a.begin(), a.end(), 1);
   for (int i = 0; i < n; i++) {
      if (a[i] == 1) {
         close(i);
         if (check() == true) {
            cnt -= 1;
            fuck[i] = true;
         } else {
            warm(i);
         }
         cerr << i << endl;
         for (auto sti : st) {
            cerr << (int)sti << ' ';
         }
         cerr << endl;
      }
   }

   cout << format("{0}\n", cnt);

   return 0;
}
/*

*/