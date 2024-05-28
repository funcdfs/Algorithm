// https://github.com/fengwei2002, 2023.02.22-20:04:06
// https://codeforces.com/contest/368/problem/B
// 368B. Sereja and Suffixes, Codeforces - Codeforces Round #215 (Div. 2)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, m = 0;
   cin >> n >> m;
   vector<int> a(n, 0), b(m, 0), f(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];
   for (int i = 0; i < m; i++) cin >> b[i];
   
   set<int> s;
   f.back() = 1;
   s.insert(a.back());
   
   for (int i = n - 2; i >= 0; i--) {
      int originSize = (int)s.size();
      s.insert(a[i]);
      int nowSize = (int)s.size();
      if (nowSize > originSize) {
         f[i] = f[i + 1] + 1;
      } else {
         f[i] = f[i + 1];
      }
   }
   
   for (int i = 0; i < m; i++) {
      cout << f[b[i] - 1] << '\n';
   }
   
   return 0;
}

/*

368B有多少个不同的元素



*/