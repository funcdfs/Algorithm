// LINK: https://codeforces.com/contest/977/problem/F
// NAME: 977F. Consecutive Subsequence, Codeforces - Codeforces Round #479 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.10.25-21:10:54, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<int> a(n, 0); 
   for (int i = 0; i < n; i++) {
      cin >> a[i]; 
   }
   
   map<int, int> f; 
   int ans = 0; 
   int lst = 0; 
   for (int i = 0; i < n; i++) {
      int x = a[i]; 
      f[x] = f[x - 1] + 1; 
      if (ans < f[x]) {
         ans = f[x]; 
         lst = x; 
      }
   }
   
   vector<int> res; 
   for (int i = n - 1; i >= 0; i--) {
      if (a[i] == lst) {
         res.push_back(i); 
         lst--; 
      }
   }
   
   cout << ans << '\n'; 
   reverse(res.begin(), res.end()); 
   for (int i = 0; i < (int)res.size(); i++) {
      cout << res[i] + 1 << " \n"[i == ans];
   }
   
   return 0;
}


/*

977F最长连续上升子序列


求一个最长的值连续上升的子序列，要求输出长度和每个元素的位置

每次读进来一个数字，压进 map 
动态转移方程就是 f[i] = max(f[i - 1] + 1, f[i]); 


*/