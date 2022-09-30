// LINK: https://codeforces.com/contest/1559/problem/D1
// NAME: 1559D1. Mocha and Diana (Easy Version), Codeforces - Codeforces Round
// #738 (Div. 2) DATE: 2022.09.28 19:58:16, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0, m1 = 0, m2 = 0;
   cin >> n >> m1 >> m2;

   vector<int> p1(n + 1), p2(n + 1);
   for (int i = 1; i <= n; i++) {
      p1[i] = i;
      p2[i] = i;
   }
   function<int(vector<int>&, int)> f = [&](vector<int>& p, int u) {
      return p[u] == u ? u : p[u] = f(p, p[u]);
   };

   for (int i = 1; i <= m1; i++) {
      int u = 0, v = 0;
      cin >> u >> v;
      p1[f(p1, u)] = f(p1, v);
   }

   for (int i = 1; i <= m2; i++) {
      int u = 0, v = 0;
      cin >> u >> v;
      p2[f(p2, u)] = f(p2, v);
   }

   vector<pair<int, int>> vp;
   for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
         int i1 = f(p1, i), j1 = f(p1, j);
         int i2 = f(p2, i), j2 = f(p2, j);
         if (i1 != j1 and i2 != j2) {
            vp.push_back({i, j});
            p1[i1] = j1;
            p2[i2] = j2;
         }
      }
   }

   cout << vp.size() << '\n';
   for (auto& [x, y] : vp) {
      cout << x << ' ' << y << '\n';
   }
   return 0;
}

/*

1559D1两个图中连边使得最终无环求最多的添加数量


两个图不同，但是每一次连边都要在两个图中连相同的边，而且连完之后不能成环

不能成环的限制其实就是，如果原本两点之间又可以直接或者间接到达的边的话，那么就不能连这两个点
否则就会成环

换句话说就是，不能把同一个连通块里面的边连接起来，否则就会形成环


所以，最终添加的边就是可以连接不同的连通块之间的边



暴力枚举：
   枚举两两组合的所有点，如果二者原来在两个图中均不连通，那就满足条件可以相连，否则就不满足条件

tag:
   并查集

*/