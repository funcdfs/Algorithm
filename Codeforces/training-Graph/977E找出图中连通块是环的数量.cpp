// LINK: https://codeforces.com/contest/977/problem/E
// NAME: 977E. Cyclic Components, Codeforces - Codeforces Round #479 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.10.14-20:15:23, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

const int N = 2e5+10; 
int n, m, p[N], st[N], d[N]; 
int ans; 

int find(int x) {
   if (p[x] != x) {
      p[x] = find(p[x]); 
   } 
   return p[x]; 
}

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   cin >> n >> m; 
   for (int i = 1; i <= n; i++) p[i] = i; 
   for (int i = 1; i <= m; i++) {
      int a = 0, b = 0; 
      cin >> a >> b; 
      p[find(a)] = find(b); 
      d[a]++, d[b]++; 
   } 
   for (int i = 1; i <= n; i++) {
      if (d[i] != 2) st[find(i)] = 1; 
   } 
   for (int i = 1; i <= n; i++) {
      if (find(i) == i && st[find(i)] == 0) {
         ans++; 
      }
   }
   cout << ans << '\n'; 
   return 0;
}


/*

977E找出图中连通块是环的数量


保证输入无重边无自环


如何判断一个连通块是否是一个简单环：
   判断这个连通块中的所有点的度数是不是 2 即可
如何找到每一个连通块：
   使用并查集进行维护即可，合并每一条边
https://codeforces.com/contest/977/submission/176149305
*/