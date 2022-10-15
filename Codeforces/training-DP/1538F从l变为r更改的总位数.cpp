// LINK: https://codeforces.com/contest/1538/problem/F
// NAME: 1538F. Interesting Function, Codeforces - Codeforces Round #725 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.10.13-22:29:28, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      int l = 0, r = 0; 
      cin >> l >> r; 
      int64_t ans = 0; 
      while (r > 0) {
         ans += (r - l); 
         r /= 10; 
         l /= 10; 
      } 
      cout << ans << '\n'; 
   }

   return 0;
}


/*
1538F从l变为r更改的总位数

![](https://p9.toutiaoimg.com/origin/pgc-image/7860b5b347154a2eb46eaa099921707f)
TODO 数位DP

假设数字从两位数变为了三位数，那么就需要统计这三位数字的变化次数之和
对于个位数，变了 111 - 99 = 12 次
100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111 

统计完个位数的变化之后，这个个位数就再也没用了 
r /= 10, l /= 10 

然后重复之前的过程
*/