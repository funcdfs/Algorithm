// URL: https://www.acwing.com/problem/content/1108/
// NAME: 山峰和山谷的数量, AcWing
// LIMIT: 64 MB, 1000 ms, DATE: 2022-08-21 13:28:07

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 4
#define dline() 2
#endif
/*----------------------------------*/

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n = 0;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    vector<vector<bool>> st(n, vector<bool>(n, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    function<void(int, int, bool&, bool&)> bfs =
        [&](int sx, int sy, bool& hasHigher, bool& hasLower) {
            queue<pair<int, int>> que;
            que.push({sx, sy});
            st[sx][sy] = true;

            while (que.size()) {
                auto [tx, ty] = que.front();
                que.pop();

                for (int a = tx - 1; a <= tx + 1; a++) {
                    for (int b = ty - 1; b <= ty + 1; b++) {
                        if (a == tx && b == ty) continue;
                        if (a < 0 || a >= n || b < 0 || b >= n) continue;

                        if (g[a][b] > g[tx][ty]) {
                            hasHigher = true;
                        } else if (g[a][b] < g[tx][ty]) {
                            hasLower = true;
                        } else {
                            if (st[a][b] == true) continue;
                            que.push({a, b});
                            st[a][b] = true;
                        }
                    }
                }
            }
        };

    int peakCnt = 0, valleyCnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (st[i][j] == false) {
                bool hasHigher = false;
                bool hasLower = false;
                bfs(i, j, hasHigher, hasLower);

                if (hasHigher == false) peakCnt++;
                if (hasLower == false) valleyCnt++;
            }
        }
    }

    cout << peakCnt << ' ' << valleyCnt << "\n";

    return 0;
}

/*

八连通

- 所有的格子都有相同的高度
- 所有的格子都连通
- 相比周围的格子，最大的叫做山峰，最小的叫做山谷

输出山峰和山谷的数量



*/