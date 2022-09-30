// LINK: https://codeforces.com/contest/1684/problem/C
// NAME: 1684C. Column Swapping, Codeforces - Codeforces Round #792 (Div. 1 +
// Div. 2) DATE: 2022.09.29 10:45:46, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int main() {
   cin.tie(nullptr), ios::sync_with_stdio(false);

   int tt = 0;
   cin >> tt;
   while (tt--) {
      int n = 0, m = 0;
      cin >> n >> m;
      vector g(n, vector<int>(m, 0));
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < m; j++) {
            cin >> g[i][j];
         }
      }

      function<pair<int, int>()> solve = [&]() -> pair<int, int> {
         int row = -1;
         for (int i = 0; i < n; i++) {
            if (!is_sorted(g[i].begin(), g[i].end())) {
               row = i;
               break;
            }
         }
         if (row == -1) return {1, 1};

         int pos1 = -1, pos2 = -1;

         auto t = g[row];
         sort(t.begin(), t.end());
         for (int i = 0; i < m; i++) {
            for (int i = 0; i < (int)t.size(); i++) {
               if (pos1 != -1 && pos2 != -1) break;
               if (t[i] != g[row][i] && pos1 == -1) {
                  pos1 = i;
                  continue;
               }
               if (t[i] != g[row][i] && pos1 != -1) {
                  pos2 = i;
                  continue;
               }
            }
         }
         dbg(g[row], pos1, pos2);

         for (int i = 0; i < n; i++) {
            swap(g[i][pos1], g[i][pos2]);
         }
         int cnt = 0;
         for (int i = 0; i < n; i++) {
            if (is_sorted(g[i].begin(), g[i].end())) {
               cnt++;
            } else {
               break;
            }
         }
         if (cnt == n) {
            return {pos1, pos2};
         }

         return {-1, -1};
      };

      auto t = solve();
      if (t.first == -1) {
         cout << -1 << '\n';
      } else {
         if (t.first == t.second) {
            cout << t.first << ' ' << t.second << '\n';
         } else {
            cout << t.first + 1 << ' ' << t.second + 1 << '\n';
         }
      }
   }

   return 0;
}

/*

1684C交换一次矩阵中的列使得矩阵中的每一行都是非严格单调递增的


n, m 2 * 1e5 数据量

*/