// LINK: https://codeforces.com/contest/1741/problem/A
// NAME: 1741A. Compare T-Shirt Sizes, Codeforces - Codeforces Round #826 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.06-22:39:09, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto f(auto a) -> int32_t {
   if (a == "M") {
      return 0; 
   } else if (a.back() == 'S') {
      return -int(a.length());
   } else {
      return a.length();
   }
}

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      string a = "", b = ""; 
      cin >> a >> b; 
      int x = f(a), y = f(b); 
      if (x < y) {
         cout << '<'; 
      } else if (x == y) {
         cout << '=';
      } else {
         cout << '>';
      }
      cout << '\n';
   }
   
   return 0;
}

/*

1741A比较衣服的尺码

*/