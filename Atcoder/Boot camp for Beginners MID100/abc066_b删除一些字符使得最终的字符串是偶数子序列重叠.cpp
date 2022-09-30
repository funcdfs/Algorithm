// LINK: https://atcoder.jp/contests/abc066/tasks/abc066_b
// NAME: B - ss, AtCoder - AtCoder Beginner Contest 066
// DATE: 2022.09.27 20:05:53, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif



int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   string s = ""; 
   cin >> s; 
   
   stack<int> stk; 
   int n = s.size(); 
   
   int ans = 0; 
   dbg(s); 
   dbg("hi"); 
   for (int i = 2; i < n; i += 2) {
      int m = (n - i) / 2; 
      // mid node is m 
      string l = s.substr(0, m); 
      string r = s.substr(m, m); 
      dbg(l, r); 
      if (l == r) {
         ans = n - i; 
         break; 
      }
   }
   cout << ans << '\n'; 
   
   return 0;
}


/*

删除一些字符使得最终的字符串是偶数子序列重叠

输出重叠的最大长度

*/