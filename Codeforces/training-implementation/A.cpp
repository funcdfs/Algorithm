// LINK: https://codeforces.com/contest/1611/problem/A
// NAME: 1611A. Make Even, Codeforces - Codeforces Round #756 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.06-14:39:57, 1000 ms

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
      string n = ""; 
      cin >> n; 
      vector<int> evenPos(0, 0); 
      for (int i = 0; i < (int)n.size(); i++) {
         int x = n[i] - '0'; 
         if (x % 2 == 0) {
            evenPos.push_back(i); 
         }
      }
      int ans = numeric_limits<int32_t>::max();
      if (evenPos.empty()) {
         ans = -1; 
      } else if (evenPos.rbegin()[0] == (int)n.size() - 1) {
         ans = 0; 
      } else if (evenPos[0] == 0) {
         ans = 1; 
      } else if ((int)evenPos.size() > 0) {
         ans = 2; 
      }
      dbg(n);
      cout << ans << '\n'; 
   }
   
   
   return 0;
}

/*

1611A使用最少的反转步数使得n变为偶数

ooxoox
xoooox

*/