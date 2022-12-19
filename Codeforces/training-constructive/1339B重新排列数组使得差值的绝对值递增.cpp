// https://github.com/fengwei2002, 2022.12.19-15:30:52
// https://codeforces.com/contest/1339/problem/B
// 1339B. Sorted Adjacent Differences, Codeforces - Codeforces Round #633 (Div. 2)

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0;
      cin >> n;
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) cin >> a[i];

      sort(a.begin(), a.end());
      int m = n / 2;
      vector<int> b{a[m]};
      for (int i = 1; i <= m; i++) {
         b.push_back(a[m - i]);
         if (m + i < n) {
            b.push_back(a[m + i]);
         }
      }
      for (int i = 0; i < n; i++) {
         cout << b[i] << " \n"[i == n - 1];
      }
   }

   return 0;
}

/*

1339B重新排列数组使得差值的绝对值递增

|a[1] - a[2]| <= |a[2] - a[3]| ... <= |a[n - 1] - a[n]|

![](https://raw.githubusercontent.com/psychonaut1f/b/main/img/202212191540538.png)
*/
