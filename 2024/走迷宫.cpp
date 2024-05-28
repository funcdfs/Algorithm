#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif



auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
   
   int n = 0, m = 0;
   cin >> n >> m;
   vector g(n, vector<int>(m, 0));
   vector d(n, vector<int>(m, 0));
   for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
         cin >> g[i][j];
      }
   }

   vector st(n, vector<bool>(m, false));

   array<int, 4> dx = {-1, 1, 0, 0};
   array<int, 4> dy = {0, 0, -1, 1};

   queue<pair<int, int>> que;
   que.push({0, 0});
   
   while (que.size()) {
      auto [tx, ty ] = que.front();
      que.pop();

      for (int i = 0; i < 4; i++) {
         int x = dx[i] + tx;
         int y = dy[i] + ty;
         if (x < 0 or x >= n or y < 0 or y >= m) continue;
         if (g[x][y] == 1 or st[x][y] == true) continue;

         que.push({x, y});
         st[x][y] = true;
         d[x][y] = d[tx][ty] + 1;
      }
   }

   if (d[n - 1][m - 1] == -1) {
      cout << -1 << endl;
   } else {
      cout << d[n - 1][m - 1] << endl;
   }
   
   return 0;
}
/*
*/