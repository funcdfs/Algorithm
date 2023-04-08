/**
 * author: https://github.com/fengwei2002
 * created: 2023-03-06 22:37:10
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
   
   // 相邻的格子有至少一个白色格子的黑色格子数 B
   // 相邻的格子有至少一个黑色格子的白色格子数 W
   // B = W + 1
   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0, m = 0;
      cin >> n >> m;
      vector<vector<char>> g(n, vector<char>(m, 'B'));
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            if ((i + j) % 2) {
               g[i][j] = 'W';
            }
         }
      }
      if (n % 2 == 1 and m % 2 == 1) {
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               cout << g[i][j];
            }
            cout << '\n';
         }
         continue;
      }
      // 如果两个数字都是奇数，直接成立
      // 否则 B 和 W 相等，将一个角上的 W 换成 B
      if (g[0][m - 1] == 'W') {
         g[0][m - 1] = 'B';
      } else if (g[n - 1][m - 1] == 'W') {
         g[n - 1][m - 1] = 'B';
      }
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            cout << g[i][j];
         }
         cout << '\n';
      }
   }
   
   return 0;
}
/*

BWBW......BWBW(B)
WBWB......WBWB(W)
..............
..............
BWBW......BWBW(B)
WBWB......WBWB(W)
(BWBW......BWBW(B))



*/