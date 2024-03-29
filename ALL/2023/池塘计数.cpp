/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-22 15:06:38
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, m = 0;
   cin >> n >> m;
   vector<vector<char>> g(n + 1, vector<char>(m + 1));
   for (int i = 0; i < n; i++) {
      for (int j= 0; j < m; j++) {
         cin >> g[i][j];
      }
   }
   
   return 0;
}
/*

*/