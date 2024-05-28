// LINK: https://codeforces.com/contest/1389/problem/B
// NAME: 1389B. Array Walk, Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.16-13:50:24, 2000 ms

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
      int n = 0, k = 0, z = 0; 
      cin >> n >> k >> z; 
      vector<int> a(n, 0); 
      for (int i = 0; i < n; i++) cin >> a[i]; 
      
      vector f(z + 1, vector<int>(n + 1, 0));
      int ans = 0; 
      for (int i = 0; i <= z; i++) { 
         // 枚举向左的步伐数量
         for (int j = 1; j <= n; j++) {
            // 枚举位置 j 
            f[i][j] = f[i][j - 1] + a[j - 1]; 
            // 第一种向右递推的方式
            if (i > 0 && j < n) {
               f[i][j] = max(f[i][j], f[i - 1][j + 1] + a[j - 1]); 
            }
            if (i * 2 + j - 1 == k) { // 走到位置 j 用了 j - 1 步
               ans = max(ans, f[i][j]); 
            }
         }
      }
      cout << ans << '\n'; 
   }

   return 0;
}


/*
1389B从下标1开始左右晃动k次向左不可以超过z次可以得到的最大的分数


同时限制不可以连续向左侧移动两次或者多次
![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20221017183752.png)
*/