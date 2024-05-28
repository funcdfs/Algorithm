// LINK: https://codeforces.com/contest/1475/problem/C
// NAME: 1475C. Ball in Berland, Codeforces - Codeforces Round #697 (Div. 3)
// CODE: https://github.com/fengwei2002, 2022.10.05-11:59:26, 2000 ms
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int A = 0, B = 0, k = 0;
      cin >> A >> B >> k;
      vector<int> a(A), b(B);
      vector<pair<int, int>> edges(k);
      for (auto& [x, y] : edges) cin >> x;
      for (auto& [x, y] : edges) cin >> y;

      for (auto& [x, y] : edges) {
         x--, y--;
         a[x]++, b[y]++;
      }
      int64_t ans = 0;
      for (auto& [x, y] : edges) {
         ans += k - (a[x] + b[y] - 1);
      }
      cout << ans / 2 << '\n';
   }

   return 0;
}

/*

1475C在给定的关系中找到两组没有重叠的组合


k 对舞伴，每对有一个男孩和一个女孩，给出双方的编号
选出两队舞伴，使得，任何一个人都不可以同时出现在两队舞伴中
求有多少种选法

think that it is given a bipartile graph
boys and girls are the vertices of the graph
if a boy and a girl are ready to dance together
then an edge is drawn between them
in this graph
you need to select two edges that do not intersect at the vertices

d[x] is the number of edges included in the vertex x
if the edge is [a, b]
it will block d[a] + d[b] - 1
apart from these edges, all other edges can satisfy the situation.

the pair number is the edges number / 2
*/