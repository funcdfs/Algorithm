// LINK: https://codeforces.com/contest/1389/problem/C
// NAME: 1389C. Good String, Codeforces - Educational Codeforces Round 92 (Rated for Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.11-17:07:38, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int solve(const string& s, int x, int y) {
   int ans = 0; 
   for (auto c : s) {
      if (c - '0' == x) {
         ans++; 
         swap(x, y); 
      } 
   }
   if (x != y && ans % 2 == 1) {
      ans = ans - 1; 
   } // 奇数的话变成偶数 
   return ans; 
}

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      string s = ""; 
      cin >> s; 
      int ans = 0; 
      for (int x = 0; x < 10; x++) {
         for(int y = 0; y < 10; y++) {
            ans = max(ans, solve(s, x, y)); 
         }
      }
      vector<int> cnt(10, 0); 
      for (auto& c : s) {
         cnt[c - '0']++; 
      } 
      for (auto& x : cnt) {
         ans = max(ans, x); 
      } // 全一样的情况
      cout << (int)s.size() - ans << '\n'; 
   }

   return 0;
}


/*

1389C左旋转一个和右旋转一个字符串相等的最少删除字符数量

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20221011180402.png)

*/