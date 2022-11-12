// LINK: https://codeforces.com/contest/839/problem/C
// NAME: C. Journey, Codeforces - Codeforces Round #428 (Div. 2)
// DATE: 2022-10-30 21:22:25, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>
using namespace std; 

const int N = 1e5 + 10; 
vector<int> g[N]; 

long double dfs(int n, int par) {
   int ch = 0; 
   long double ans = 0; 
   for (auto e : g[n]) {
      if (e != par) {
         ans += dfs(e, n); 
         ch++; 
      }
   }
   if (ch == 0) return 0; 
   return 1 + ans / ch; 
}

int main() {
   cin.tie(0)->sync_with_stdio(false);
   cout << setprecision(15) << fixed; 
   
   int n = 0; 
   cin >> n; 
   for (int i = 0; i < n - 1; i++) {
      int x = 0, y = 0; 
      cin >> x >> y; 
      g[x].push_back(y); 
      g[y].push_back(x); 
   }
   
   cout << dfs(1, -1); 
   
   return 0;
}

/*
839C求期望平均路径长度

就是一个图中，从点 1 出发
等概率的进行扩散
每一条边的权重都是 1 
求停止的时候总的权重的平均长度是多少 


*/