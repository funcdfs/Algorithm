// LINK: https://www.luogu.com.cn/problem/CF1325C
// NAME: CF1325C Ehab and Path-etic MEXs, Luogu
// CODE: https://github.com/fengwei2002, 2022.10.31-22:43:19, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/* ------------------------------------------ */
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/* ------------------------------------------ */



int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   vector<vector<int>> e(n); 
   vector<int> id(n - 1, -1); 
   for (int i = 0; i < n - 1; i++) {
      int u = 0, v = 0; 
      cin >> u >> v; 
      u--, v--; 
      e[u].push_back(i); 
      e[v].push_back(i); 
   }
   
   int c = 0; 
   for (int i = 0; i < n; i++) {
      if ((int)e[i].size() >= 3) {
         for (int j = 0; j < 3; j++) {
            id[e[i][j]] = j; 
         }
         c = 3; 
         break; 
      }
   }
   
   for (int i = 0; i < n - 1; i++) {
      if (id[i] == -1) {
         id[i] = c++; 
      }
   }
   // 除了 0 1 2 都随便赋值
   
   for (int i = 0; i < n - 1; i++) {
      cout << id[i] << '\n'; 
   }
   return 0;
}


/*

1325C重新整理边的权值使得树中的MEXu,v最大值最小


如果是一个链条，那么最终的值是确定的 n - 1

因为确切的拥有 n 个节点和 n - 1 个边
如果不是一个链条，可以找到一个度数大于等于 3 的点，将他的任意三个连边填上 012
然后对于其他的两个点，如果不经过 这个结点，MEX(u, v) 就是 2 
如果经过这个结点，MEX(u, v) 就是 0 1 2 中的一个值

因为最终取值是最大值的最小值，也就是 2 
*/