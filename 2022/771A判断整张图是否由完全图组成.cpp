// LINK: https://codeforces.com/contest/771/problem/A
// NAME: 771A
// CODE: https://github.com/fengwei2002, 2022.10.26-17:07:41, 1000 ms

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int64_t fa[150010], num[150010]; 
int64_t sum; 
int fi(int x) {
   if (fa[x] == x) {
      return x; 
   } else {
      return fa[x] = fi(fa[x]); 
   }
}

void add(int x, int y) {
   int xx = fi(x), yy = fi(y); 
   if (xx == yy) return; 
   fa[yy] = xx;
   num[xx] += num[yy]; 
   num[yy] = 0; 
}

int main() {
   int64_t n = 0, m = 0; 
   cin >> n >> m; 
   for (int i = 1; i <= n; i++) {
      fa[i] = i; 
      num[i] = 1; 
   }
   
   for (int i = 1; i <= m; i++) {
      int64_t x = 0, y = 0; 
      cin >> x >> y; 
      add(x, y); 
   }
   
   for (int i = 1; i <= n; i++) {
      if (num[i] > 1) {
         sum += num[i] * (num[i] - 1) / 2; // 每一个点都要和其他点相连
      }
   }
   
   if (sum == m) {
      cout << "YES\n"; 
   } else {
      cout << "NO\n"; 
   }
   return 0; 
}


/*

771A判断整张图是否由完全图组成



给出一个无向图，对于每一个点三元组 x, y, z 
如果 x, y 和 y, z 之间都存在连边，那么 x, z 之间也必须存在连边


保证两两相连的话，那么每一个连通块都必须是一个完全图，如果连通块存在 i 个点
那么对边数的贡献就是 i * (i - 1) / 2; 

*/