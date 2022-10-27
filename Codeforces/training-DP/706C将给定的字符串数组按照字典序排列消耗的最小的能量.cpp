// LINK: https://codeforces.com/contest/706/problem/C
// NAME: 706C. Hard problem, Codeforces - Codeforces Round #367 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.19-09:57:59, 1000 ms

#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long int;

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   int n = 0; 
   cin >> n; 
   vector<int> c(n, 0); 
   vector<string> strs(n, ""); 
   for (int i = 0; i < n; i++) cin >> c[i]; 
   for (int i = 0; i < n; i++) cin >> strs[i];
   vector<vector<ull>> f(n + 1, vector<ull>(2, (1 << 31))); 
   // 当数据类型变化的时候，就不要使用省略类型的写法了
   f[1][0] = 0, f[1][1] = c[0]; 
   // 数量为 1 的时候
   
   for (int i = 2; i <= n; i++) {
      string x1 = strs[i - 1], x2 = strs[i - 1]; 
      string y1 = strs[i - 2], y2 = strs[i - 2]; 
      reverse(x2.begin(), x2.end()); 
      reverse(y2.begin(), y2.end()); 
      if (x1 >= y1) f[i][0] = min(f[i][0], f[i - 1][0]); 
      if (x1 >= y2) f[i][0] = min(f[i][0], f[i - 1][1]);  
      if (x2 >= y1) f[i][1] = min(f[i][1], f[i - 1][0] + c[i - 1]); 
      if (x2 >= y2) f[i][1] = min(f[i][1], f[i - 1][1] + c[i - 1]); 
   }
   ull ans = min(f[n][0], f[n][1]); 
   if (ans == (1 << 31)) {
      cout << -1 << '\n';
      return 0; 
   } else {
      cout << ans << '\n'; 
   }
   return 0;
}


/*

706C将给定的字符串数组按照字典序排列消耗的最小的能量


![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20221019105756.png)
*/