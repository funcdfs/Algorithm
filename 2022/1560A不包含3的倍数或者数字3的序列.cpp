// LINK: https://codeforces.com/contest/1560/problem/A
// NAME: 1560A. Dislike of Threes, Codeforces - Codeforces Round #739 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.12.05-21:12:03, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   vector<int> f(0, 0); 
   f.reserve(2000); 
   for (int i = 1; i <= 2000; i++) {
      if (i % 3 != 0 && i % 10 != 3) {
         f.push_back(i);
      }
   }
   
   int tt = 0; 
   cin >> tt; 
   while (tt--) {
      int k = 0; 
      cin >> k; 
      cout << f[k - 1] << '\n';
   }
   
   return 0;
}

/*

1560A不包含3的倍数或者数字3的序列

*/