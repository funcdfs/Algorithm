// LINK: https://codeforces.com/contest/1418/problem/C
// NAME: 1418C. Mortal Kombat Tower, Codeforces Round 95 (Rated for Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.15-13:37:28, 1000 ms

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
      int n = 0;
      cin >> n;
      vector<int> a(n, 0);
      for (int i = 0; i < n; i++) cin >> a[i];
      
      int ans = 0; 
      if (a[0] == 1) ans++; 
      for (int i = 1; i < n; i++) {
         if (a[i] == 0) continue; 
         int j = i; 
         while (j < n && a[j] == 1) j++; 
         ans += (j - i) / 3; 
         i = j - 1; 
      }
      cout << ans << '\n'; 
   }

   return 0;
}


/*
1418C朋友可以拿到的最少的1的数量

给定 n 个数字，你和你的朋友轮流操作，你的朋友先手，从头一次取出一个或者两个数 
求你的朋友取出 1 的数量的最小值

也就是等价于我自己取出更多的 1 
首先第一个数字肯定是朋友先取 
之后每一段以 1 开头的连续为 1 的串 
都可以以我为开头，所以只需要统计除去开头之外的所有的连续的为 1 的串的长度
除以 3 加入答案即可

*/