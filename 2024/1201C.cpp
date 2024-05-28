/**
 * name: C. Maximum Median
 * link: https://codeforces.com/contest/1201/problem/C
 * time: 2024/5/26 14:21:47 https://github.com/funcdfs
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
   
   int n = 0, k = 0;
   cin >> n >> k;
   vector<int> a(n, 0);
   for (int i = 0; i < n; i++) {
      cin >> a[i];
   }
   ranges::sort(a);

   int idx = n / 2;
   int base = a[idx];
   int cnt = 1;

   while (k > 0 and idx + 1 < n) {
      int val = min(k / cnt, a[idx + 1] - base);
      base += val;
      k -= val * cnt;
      cnt += 1;
      idx += 1;
   }
   if (k > 0) {
      base += k / cnt;
   }

   cout << base;

   return 0;
}
/*
1 1 1 1 2 [5]
1 1 2 2 2 [3]
1 1 3 3 3 [0]
*/