// LINK: https://codeforces.com/contest/1336/problem/A
// NAME: 1336A. Linova and Kingdom, Codeforces - Codeforces Round #635 (Div. 1)
// CODE: https://github.com/fengwei2002, 2022.10.11-11:37:34, 2000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(0)->sync_with_stdio(false);
   
   int n = 0, k = 0;
   cin >> n >> k;
   vector e(n + 1, vector<int>(0, 0));
   for (int i = 0; i < n - 1; i++) {
      int u = 0, v = 0;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
   }
   
   vector<int> dep(n + 1, 0); 
   dep[1] = 1; 
   // 根节点的深度为第一层
   
   vector<int> sz(n + 1, 0); 
   function<void(int, int)> dfs = [&](int nowNode, int parent) {
      sz[nowNode] = 1; 
      for (auto& nextNode : e[nowNode]) {
         if (nextNode == parent) continue;
         dep[nextNode] = dep[nowNode] + 1; 
         dfs(nextNode, nowNode); 
         sz[nowNode] += sz[nextNode]; 
      }
   };
   dfs(1, 0);
   
   vector<int> id(n, 0); 
   iota(id.begin(), id.end(), 1); 
   sort(id.begin(), id.end(), [&](int a, int b) {
      return dep[a] - sz[a] > dep[b] - sz[b]; 
   }); 
   
   int64_t ans = 0; 
   for (int i = 0; i < k; i++) {
      ans += dep[id[i]] - sz[id[i]]; 
   }
   cout << ans << '\n'; 
   return 0;
}

/*

1336A选择k个工业城市使得总路径上的旅游业城市的数量总和最大


![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20221011160555.png)
*/