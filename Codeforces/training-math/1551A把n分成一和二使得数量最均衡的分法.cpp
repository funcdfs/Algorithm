// LINK: https://codeforces.com/contest/1551/problem/A
// NAME: 1551A. Polycarp and Coins, Codeforces - Codeforces Round #734 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.05-15:33:18, 1000 ms

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
      int n = 0; 
      cin >> n; 
      /*
      int c1 = 0; 
      int c2 = 0; 
      if (n % 2 != 0) {
         c1 = 1; 
         c2 = n / 2; 
         n / 2 - x      vs 1 + 2x   
         n / 2 - 3x - 1 vs 0
         x              vs n / 2 - 1 div 3

         double x = (n / 2 - 1) / 3.0;
         dbg(x);
      }
      */
      int a = n / 3, b = n / 3; 
      if (n % 3 == 1) a++; 
      else if (n % 3 == 2) b++; 
      cout << a << ' ' << b << '\n';
   }
   
   return 0;
}

/*

1551A把n分成一和二使得数量最均衡的分法

*/