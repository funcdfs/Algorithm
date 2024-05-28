// https://github.com/fengwei2002, 2023.02.22-19:52:25
// https://codeforces.com/contest/474/problem/B
// 474B. Worms, Codeforces - Codeforces Round #271 (Div. 2)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) cin >> a[i];
   // 第 i 堆中有 a[i] 个蚯蚓
   
   for (int i = 0; i + 1 < n; i++) {
      a[i + 1] += a[i];
   }
   int m = 0;
   cin >> m;
   while (m--) {
      int q = 0;
      cin >> q;
      // 正确的回答，q 这个蚯蚓，在哪一堆中，就可以得到蚯蚓
      cout << lower_bound(a.begin(), a.end(), q) - a.begin() + 1 << '\n';
   }
   
   return 0;
}

/*

474B蚯蚓在第几堆



*/