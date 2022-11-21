// LINK: https://codeforces.com/contest/1338/problem/A
// NAME: 1338A. Powered Addition, Codeforces - Codeforces Round #633 (Div. 1)
// CODE: https://github.com/fengwei2002, 2022.11.19-20:26:59, 1000 ms

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
      
      vector<int> b(0, 0); 
      int maxVal = (int)-2e9; 
      b.reserve(n); 
      
      for (int i = 0; i < n; i++) {
         int x = max({maxVal, a[i]}); 
         b.push_back(x); 
         maxVal = max({maxVal, x}); 
      }
      
      int maxDiff = (int)-2e9; 
      for (int i = 0; i < n; i++) {
         maxDiff = max(maxDiff, (b[i] - a[i])); 
      }
      int64_t ans = 0; 
      while ((1ll << ans) - 1 < maxDiff) {
         ans++; 
      }
      cout << ans << '\n'; // 多少位的 1 可以 cover maxDiff 
   }
   
   return 0;
}
/*

1338A使得a非严格单调递增的最少操作次数

1
2
4
8
...

1 7 6 5 
2^0: 1 7 7 6 
2^1: 1 7 7 8 
cout << 2 << '\n'; 

从前往后遍历字符串的话，可以解决问题，但是不是最小的方案数量

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/%E6%A8%AA%E7%89%88%E8%8D%89%E7%A8%BF%E7%BA%B8%20P8.png)


*/