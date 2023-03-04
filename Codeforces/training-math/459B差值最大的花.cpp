// https://github.com/fengwei2002, 2023.03.01-23:22:32
// https://codeforces.com/contest/459/problem/B
// 459B. Pashmak and Flowers, Codeforces - Codeforces Round #261 (Div. 2)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0;
   cin >> n;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   
   // 想要两个差值最大的花
   // 返回可以得到的最大的差值，并且要统计 最大差值的数量
   
   sort(a.begin(), a.end());
   int maxDiff = a.rbegin()[0] - a.begin()[0];
   dbg(maxDiff);
   
   unordered_map<int, int64_t> hs;
   for (int i = 0; i < n; i++) {
      hs[a[i]] += 1;
   }
   
   if (maxDiff == 0) {
      // 说明所有的数字相同，也就是从 n 个中选出两个的方案数量  Cn2
      cout << maxDiff << ' ' << (int64_t)n * (n - 1) / 2;
   } else {
      cout << maxDiff << ' ' << hs[a[0]] * hs[a[n - 1]] << '\n';
   }
   
   
   return 0;
}

/*
459B差值最大的花

cn2 = n! / (n - 2)!2!

= n * n - 1 / 2
*/