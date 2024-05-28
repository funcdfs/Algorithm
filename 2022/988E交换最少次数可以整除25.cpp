// LINK: https://codeforces.com/contest/988/problem/E
// NAME: E. Divisibility by 25, Codeforces - Codeforces Round #486 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.11.27-11:39:03, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   string num = ""; cin >> num; 
   
   auto f = [&](char a, char b) -> int32_t {
      string s = num; 
      int len = (int)s.size(); 
      
      int p1 = s.rfind(b); 
      if (p1 == -1) return numeric_limits<int32_t>::max(); 
      s.erase(p1, 1); 
      
      int p2 = s.rfind(a); 
      if (p2 == -1) return numeric_limits<int32_t>::max(); 
      s.erase(p2, 1); 
      
      int zeroCnt = 0; 
      while (s[zeroCnt] == '0') zeroCnt++; 
      return zeroCnt + (len - p1 - 1) + (len - p2 - 2); 
   };
   
   int ans = min({
      f('0', '0'), 
      f('2', '5'), 
      f('5', '0'), 
      f('7', '5'),
   }); 
   
   if (ans == numeric_limits<int32_t>::max()) {
      cout << -1 << '\n'; 
   } else {
      cout << ans << '\n'; 
   }
   
   return 0;
}

/*

988E交换最少次数可以整除25

给定一个字符串，每次可以交换两个相邻的元素，且交换完之后前缀不是 0 
问最少交换几次，可以使得，这个字符串的后缀是 00 25 50 75

(len — pos1 - 1) + (len - pos2 - 2)

*/