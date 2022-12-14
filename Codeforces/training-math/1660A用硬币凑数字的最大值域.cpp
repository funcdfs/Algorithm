// LINK: https://codeforces.com/contest/1660/problem/A
// NAME: 1660A. Vasya and Coins, Codeforces - Codeforces Round #780 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.06-16:02:17, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      int a = 0, b = 0; 
      cin >> a >> b; 
      
      if (a == 0) {
         cout << 1 << '\n'; 
      } else {
         cout << a + 2 * b + 1 << '\n'; 
      }
   }
   
   return 0;
}

/*

1660A用硬币凑数字的最大值域

*/