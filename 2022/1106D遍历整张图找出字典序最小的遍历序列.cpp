// LINK: https://codeforces.com/contest/1106/problem/D
// NAME: 1106D. Lunar New Year and a Wander, Codeforces - Codeforces Round #536 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.11.03-19:39:34, 3000 ms

#include <bits/stdc++.h>
using namespace std;
/* ------------------------------------------ */
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/* ------------------------------------------ */

const int N = 1e5 + 10; 
vector<int> g[N]; 
bool st[N]; 

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, m = 0; 
   cin >> n >> m; 
   for (int i = 0; i < m; i++) {
      int u = 0, v = 0; 
      cin >> u >> v; 
      g[u].push_back(v); 
      g[v].push_back(u); 
   }
   
   priority_queue<int, vector<int>, greater<>> que; 
   que.push(1); 
   st[1] = true; 
   
   while (que.empty() == false) {
      auto t = que.top(); 
      que.pop(); 
      cout << t << ' '; 
      for (int i : g[t]) {
         if (st[i] == false) {
            que.push(i); 
            st[i] = true; 
         }
      }
   }
   
   return 0;
}


/*

1106D遍历整张图找出字典序最小的遍历序列

*/