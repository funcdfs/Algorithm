// LINK: https://codeforces.com/contest/1535/problem/C
// NAME: 1535C. Unstable String, Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.03-14:13:17, 2000 ms

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
      string s = ""; 
      cin >> s; 
      int n = (int)s.size(); 
      vector f(n + 1, vector<int>(2, 0)); 
      
      for (int i = 1; i <= n; i++) {
         if (s[i - 1] == '?') {
            f[i][0] = f[i - 1][1] + 1; 
            f[i][1] = f[i - 1][0] + 1; 
         } else if (s[i - 1] == '0') {
            f[i][0] = f[i - 1][1] + 1; 
         } else if (s[i - 1] == '1') {
            f[i][1] = f[i - 1][0] + 1; 
         }
      }
      
      int64_t ans = 0; 
      for (int i = 1; i <= n; i++) {
         ans += max(f[i][0], f[i][1]); 
      }
      cout << ans << '\n'; 
   }

   return 0;
}


/*

1535C将问号替换为01之后的美丽子字符串的数量


beauty string: any tow adjacent char are different 


设 f[i] 表示以 i 结尾的不稳定子串的数量 
f[i][0] 表示第 i 位是 0，以 i 结尾的 ustable 数量 
f[i][1] 表示第 i 位是 1，以 i 结尾的 ustable 数量

当 s1 = 1, 存在 f[i][1] = f[i - 1][0] + 1
当 si = 0, 存在 f[i][0] = f[i - 1][1] + 1 
当 si = ?, 存在 f[i][1] = f[i - 1][0] + 1, f[i][0] = f[i - 1][1] + 1 

然后再扫描一遍 f 数组，把每一个 max(f[i][1], f[i][0]) 加起来就是答案了

状态机DP
*/