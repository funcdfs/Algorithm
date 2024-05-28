// LINK: https://codeforces.com/contest/978/problem/E?f0a28=1
// NAME: 978E. Bus Video System, Codeforces - Codeforces Round #481 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.11.26-22:44:53, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, w = 0; 
   cin >> n >> w; 
   vector<int> a(n, 0); 
   for (int i = 0; i < n; i++) cin >> a[i]; 
   
   vector<int64_t> preSum(n + 1, 0); 
   for (int i = 1; i <= n; i++) {
      preSum[i] = preSum[i - 1] + a[i - 1]; 
   }
   
   int minVal = *min_element(preSum.begin() + 1, preSum.end()); 
   int maxVal = *max_element(preSum.begin() + 1, preSum.end()); 
   dbg(a, preSum); 
   dbg(minVal, maxVal); 
   int right = w - maxVal; 
   int left = -minVal; 
   dbg(right, left); 
   
   int t = min(w, right) - max(0, left) + 1;
   if (t < 0) {
      cout << 0 << '\n'; 
   } else {
      cout << t << '\n'; 
   }
   return 0;
}

/*

978E公交车初始人数的可能的数量是多少

设上车前的人数为 x 
中途最大的人数为 x + max 
中途最少的人数为 x + min 

那么就存在不等式组： 
   x + max <= w; 
   x + min >= 0; 
   
求出 max 和 min 之后，就得到了 x 的具体的范围 

0 - min <= x <= w - max

*/