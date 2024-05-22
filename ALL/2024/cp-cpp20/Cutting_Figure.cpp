/**
 * name: Cutting Figure
 * link: https://www.luogu.com.cn/problem/CF193A
 * time: 2024/5/18 14:33:15 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> n >> m;
    vector g(n, vector<char>(m, ' '));
    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '#') {
                total += 1;
            }
        }
    }
    if (total < 3) {
        cout << format("-1\n");
        return 0;
    }
    vector st(n, vector<bool>(m, false));
    array<int, 4> dx = {-1, 1, 0, 0};
    array<int, 4> dy = {0, 0, -1, 1};

    int cnt = 0;
    function<void(int, int)> dfs = [&](int x, int y) -> void {
        for (int i = 0; i < 4; i++) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;
            if (tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
            if (st[tx][ty] == true) continue;
            if (g[tx][ty] != '#') continue;

            st[tx][ty] = true;
            cnt += 1;
            dfs(tx, ty);
        }
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '#') {
                for (cnt = 0; auto& sti : st) {
                    fill(sti.begin(), sti.end(), false);
                }
                g[i][j] = '.';
                for (int d = 0; d < 4; d++) {
                    int tx = i + dx[d];
                    int ty = j + dy[d];
                    if (tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
                    if (g[tx][ty] != '#') continue;
                    dfs(tx, ty);
                    if (cnt > 0) {
                        break;
                    }
                }
                g[i][j] = '#';

                dbg(i, j, cnt);
                if (cnt < total - 1) {
                    cout << format("1\n");
                    return 0;
                }
            }
        }
    }

    cout << format("2\n");

    return 0;
}
/*

*/