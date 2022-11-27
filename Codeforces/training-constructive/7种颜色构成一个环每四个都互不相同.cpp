// LINK: https://www.acwing.com/problem/content/4720/
// NAME: 环形队伍, AcWing
// CODE: https://github.com/fengwei2002, 2022.11.25-22:58:58, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif



auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   string hat = "ROYGBIV"; 
   int n = 0; 
   cin >> n; 
   
   string ans = ""; 
   for (int i = 0; i < n - 3; i++) {
      ans += hat[i % 4];
   }
   
   for (int i = 0; i < 3; i++) {
      ans += hat[i + 4]; 
   }
   
   cout << ans << '\n'; 
   
   return 0;
}

/*

7种颜色构成一个环每四个都互不相同

*/