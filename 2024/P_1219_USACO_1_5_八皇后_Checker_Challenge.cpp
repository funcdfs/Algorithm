#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

const int N = 13;
bool row[N], col[N], rrr[N * 2], lll[N * 2];

vector<vector<int>> ans;
auto main() -> int32_t {
   cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

   int n = 0;
   cin >> n;
   vector<vector<char>> g(n, vector<char>(n, '.'));
   // vector<string> ans;

   // unordered_map<int, bool> row, col, rrr, lll;
   int tot  = 0;

   function<void(int, int, int)> dfs = [&](int x, int y, int cnt) -> void {
      if (cnt > n) return;
      if (y == n) {
         x += 1;
         y = 0;
      }
      if (x == n) {
         if (cnt == n) {
            if (tot > 3) {
               
            }
            vector<int> path(n, 0);
            int idx = 0;
            for (int i = 0; i < n; i++) {
               for (int j = 0; j < n; j++) {
                  // cout <<g[i][j];
                  if (g[i][j] == 'Q') {
                     path[idx] = j + 1;
                     idx += 1;
                  }
               }
               // cout << endl;
            }
            ans.push_back(path);
            // cout << endl;
         }
         return;
      }
      dfs(x, y + 1, cnt);

      if (row[x] == false and col[y] == false and rrr[x - y + n] == false and
          lll[x + y] == false) {
         row[x] = col[y] = rrr[x - y + n] = lll[x + y] = true;
         g[x][y] = 'Q';
         dfs(x, y + 1, cnt + 1);
         g[x][y] = '.';
         row[x] = col[y] = rrr[x - y + n] = lll[x + y] = false;
      }
   };

   dfs(0, 0, 0);

dbg(ans.size());
dbg(ans[0]);
   ranges::sort(ans, [&](auto& a, auto& b) {
      for (int i = 0; i < n; i++) {
         if (a[i] < b[i]) {
            return true;
         }
      }
      return false;
   });
dbg(ans.size());
dbg(ans[0]);
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < n; j++) {
         cout << ans[i][j] << ' ';
      }
      cout << endl;
   }

   cout << (int)ans.size() << endl;

   return 0;
}
/*

*/