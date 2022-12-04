// LINK: https://www.acwing.com/problem/content/93/
// NAME: 最短Hamilton路径, AcWing
// CODE: https://github.com/fengwei2002, 2022.11.27-23:10:41, 5000 ms

#include <bits/stdc++.h>
using namespace std;

const int N = 20, M = 1 << 20; 
int f[M][N]; 

auto main() -> int32_t {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<vector<int>> w(n, vector<int>(n, 0)); 
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
         cin >> w[i][j]; 
      }
   }
   
   memset(f, 0x3f, sizeof f); 
   f[1][0] = 0; // 第 0 位上是 1 其他所有的位置都是 0 
   // f[i][j] 表示从 0 走到 j 走过的所有点的二进制表示是 i 的所有路径
   for (int i = 0; i < (1 << n); i++) {
      for (int j = 0; j < n; j++) { // i 和 j 枚举所有的状态
         if ((i >> j) & 1) {
            for (int k = 0; k < n; k++) { // 倒数第二个点是 k 的话，枚举一下所有转移的状态 
               if ((i - (1 << j)) >> k & 1) {
                  // i 除去 j 这个点之后，必须包含 k 这个点
                  f[i][j] = min(f[i][j], f[i - (1 << j)][k] + w[k][j]); 
               }
            }
         }
      }
   }
   // n 个 1, 落脚点是 n - 1
   cout << f[(1 << n) - 1][n - 1] << '\n'; 
   return 0;
}

/*



*/