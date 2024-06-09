/**
 * name: B. OR in Matrix
 * link: https://codeforces.com/contest/486/problem/B
 * time: 2024/5/29 12:22:47 https://github.com/funcdfs
 **/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif



auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, m = 0;
   cin >> n >> m;

   vector g(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> g[i][j];
      }
   }

   
   
   return 0;
}
/*

*/