// https://github.com/fengwei2002, 2023.02.18-15:06:25
// https://codeforces.com/contest/456/problem/A
// 456A. Laptops, Codeforces - Codeforces Round #260 (Div. 2)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   int n = 0;
   cin >> n;
   vector<pair<int, int>> v(n);
   for (int i = 0; i < n; i++) {
      cin >> v[i].first >> v[i].second;
   }
   sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b) {
      if (a.first == b.first) {
         return a.second > b.second;
      }
      return a.first < b.first;
   });
   
   bool ok = true;
   for (int i = 1; i < n and ok; i++) {
      if (v[i - 1].first < v[i].first and v[i - 1].second > v[i].second) {
         ok = false;
      }
      // 价格便宜，并且价值更大
   }
   if (ok) {
      cout << "Poor Alex" << '\n';
   } else {
      cout << "Happy Alex" << '\n';
   }
   
   return 0;
}

/*

456A性价比最高的笔记本



*/