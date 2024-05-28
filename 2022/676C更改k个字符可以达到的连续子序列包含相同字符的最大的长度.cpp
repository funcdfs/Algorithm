// LINK: https://codeforces.com/contest/676/problem/C
// NAME: 676C. Vasya and String, Codeforces - Codeforces Round #354 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.13-22:57:31, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, k = 0; 
   cin >> n >> k; 
   string s = string(n, ' '); 
   cin >> s; 
   
   int l = 0, r = 0; 
   int ans = 0; 
   int a = 0, b = 0; 
   while (r < n) {
      if (s[r] == 'a') a++; 
      if (s[r] == 'b') b++; 
      if (a <= k || b <= k) { 
         // find a new change method suit for ans
         ans = max(ans, r - l + 1); 
      } else {
         if (s[l] == 'a') a--; 
         if (s[l] == 'b') b--; 
         l++; 
      }
      r++; 
   }
   
   cout << ans << '\n'; 
   
   return 0;
}


/*
676C更改k个字符可以达到的连续子序列包含相同字符的最大的长度(只包含ab的字符串)

首先可以得到 char that have max freq
然后统计他们之间的间隔

将这些可以使用的 k 尽可能的插入到两个比较大的块的中间


但是由于只存在 a 和 b 两种不同的字符(那也一样..)




*/