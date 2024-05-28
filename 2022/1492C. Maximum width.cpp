// LINK: https://codeforces.com/contest/1492/problem/C
// NAME: 1492C. Maximum width, Codeforces - Codeforces Round #704 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.16-13:27:33, 2000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, m = 0; 
   cin >> n >> m; 
   string s = string(n, ' '), t = string(m, ' '); 
   cin >> s >> t; 
   
   vector<int> pre(m, 0), suf(m, 0); 
   int j = 0; 
   for (int i = 0; i < m; i++) {
      while (s[j] != t[i]) j++; 
      pre[i] = j; 
      j++; 
   }
   j = n - 1; 
   for (int i = m - 1; i >= 0; i--) {
      while (s[j] != t[i]) j--; 
      suf[i] = j; 
      j--; 
   }
   int ans = 0; 
   for (int i = 0; i < m - 1; i++) {
      ans = max(ans, suf[i + 1] - pre[i]); 
   }
   cout << ans << '\n'; 

   return 0;
}


/*
1492C. Maximum width

给定两个由小写英文字母组成的字符串 s 和 t 
保证 t 中的每一个字符都在 s 中至少出现过一次
定义 pi 为任意一个使得 spi = ti 成立的值 
求 pi+1 - pi 的最大值 

如果要让 pi+1 - pi 最大
就需要 pi+1 尽量的大，pi 尽量的小 
所以可以对 t 中的每一个字符找出 其在 s 中最先出现的位置和最后出现的位置 

*/