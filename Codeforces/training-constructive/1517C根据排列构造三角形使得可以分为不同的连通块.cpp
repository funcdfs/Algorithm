// LINK: https://codeforces.com/contest/1517/problem/C
// NAME: 1517C. Fillomino 2, Codeforces - Contest 2050 and Codeforces Round #718 (Div. 1 + Div. 2)
// DATE: 2022.09.24 11:13:07, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/



int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0; 
   cin >> n; 
   
   vector<int> p(n, 0); 
   for (int i = 0; i < n; i++) cin >> p[i]; 
   
   vector a(n, vector<int>(n, -1)); 
   for (int i = 0; i < n; i++) {
      int x = i, y = i; 
      a[x][y] = p[i]; 
      for (int it = 1; it < p[i]; it++) { // 还需要放置的 P[i] 的数量
         if (y > 0 && a[x][y - 1] == -1) { // 逆着填充
            y--; 
         } else { // 如果这一行不可以继续向左侧填充了，就转到下一行
            x++; 
         }
         assert(a[x][y] == -1); 
         a[x][y] = p[i]; 
      }
   }
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < i + 1; j++) {
         cout << a[i][j] << " \n"[j == i]; 
      }
   }
   return 0;
}


/*

1517C根据排列构造三角形使得可以分为不同的连通块

给定一个长度为 n 个排列 P
- 三角形共 n 行， 第 i 行有 i 个数字，第 i 行的最后一个数字是 P[i] 
- 接下来构造 n 个连通块，对于第 x 个连通块，每一个元素，**连通块的大小都必须等于 x**
- 三角形的每一个格子都必须恰好填充一个数字 

for (int i = 0; i < n; i++) {
   for (int j = 0; j < i + 1; j++) {
      cout << a[i] << " \n"[j == i]; 
   }
}

但是每一个连通块的大小都必须等于 x 


*/