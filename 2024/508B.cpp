/**
 * name: B. Anton and currency you all know
 * link: https://codeforces.com/contest/508/problem/B
 * time: 2024/5/25 22:47:16 https://github.com/funcdfs
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

   string s;
   cin >> s;

   vector<int> a((int)s.size(), 0);
   for (int i = 0; i < (int)s.size(); i++) {
      a[i] = s[i] - '0';
   }
   dbg(a);

   vector<pair<int, int>> even;
   for (int i = 0; auto& x : a) {
      if (x % 2 == 0) {
         even.push_back({x, i});
      }
      i += 1;
   }

   if ((int)even.size() == 0) {
      cout << "-1";
      return 0;
   }

   bool ok = false;
   for (int i = 0; i < (int)even.size(); i++) {
      int& num = even[i].first;
      int& idx = even[i].second;
      if (num < a.back()) {
         swap(a[idx], a.back());
         ok = true;
         break;
      }
   }

   if (ok == false) {
      swap(a.back(), a[even.back().second]);
   }

   for (int i = 0; i < (int)a.size(); i++) {
      cout << a[i];
   }

   return 0;
}
/*

*/