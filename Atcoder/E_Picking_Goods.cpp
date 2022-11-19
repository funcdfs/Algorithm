/**
 * Code: https://github.com/fengwei2002
 * Time: 2022-11-18 17:15
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif



int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0, m = 0, k = 0; 
   cin >> n >> m >> k; 
   dbg(n, m, k); 
   vector<vector<int>> a(n + 1, vector<int>(m + 1, 0)); 
   for (int i = 0; i < k; i++) {
      int r = 0, c = 0, w = 0; 
      cin >> r >> c >> w; 
      a[r][c] = w; 
   }

   vector<vector<vector<int64_t>>> f(n + 1, vector<vector<int64_t>>(m + 1, vector<int64_t>(4, 0))); 
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
         f[i][j][0] = max({
            f[i - 1][j][1], 
            f[i - 1][j][2], 
            f[i - 1][j][3],
         }); 
         f[i][j][1] = max({
            f[i][j - 1][1], 
            f[i][j][0] + a[i][j],
         });
         f[i][j][2] = max({
            f[i][j - 1][2],
            f[i][j - 1][1] + a[i][j],
         }); 
         f[i][j][3] = max({
            f[i][j - 1][3], 
            f[i][j - 1][2] + a[i][j],
         }); 
      }
   }

   int64_t ans = 0; 
   for (int i = 0; i <= 3; i++) {
      ans = max(ans, f[n][m][i]); 
   }
   cout << ans << '\n'; 

   return 0;
}


/*

date: 2022-11-18
https://atcoder.jp/contests/abc175/tasks/abc175_e

输入 n m (1≤n,m≤3000) k(≤min(2e5,r*c))，表示一个 n*m 的网格，和网格中的 k 个物品。
接下来 k 行，每行三个数 x y v(≤1e9) 表示物品的行号、列号和价值（行列号从 1 开始）。
每个网格至多有一个物品。

你从 (1,1) 出发走到 (n,m)，每步只能向下或向右。
经过物品时，你可以选或不选，且每行至多可以选三个物品。
输出你选到的物品的价值和的最大值。

定义 f[i][j][0/1/2/3] 表示从 (1,1) 走到 (i,j)，且当前行选了 0/1/2/3 个物品时的最大价值和。

转移方程如下：

f[i][j][0] = max(f[i-1][j])
f[i][j][1] = max(f[i][j-1][1], f[i][j][0]+a[i][j])
f[i][j][2] = max(f[i][j-1][2], f[i][j-1][1]+a[i][j])
f[i][j][3] = max(f[i][j-1][3], f[i][j-1][2]+a[i][j])

答案为 max(f[n][m])。

实际计算 max(f[][]) 时，f[][][0] 可以不计入。
*/
