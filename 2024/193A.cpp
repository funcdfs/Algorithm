/**
 * name: A. Cutting Figure
 * link: https://codeforces.com/contest/193/problem/A
 * time: 2024/5/18 14:54:50 https://github.com/funcdfs
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
    vector a(n, vector<int>(m, 0));

    int total = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (char c; cin >> c and c == '#') {
                a[i][j] = 1;
                total += 1;
            }
        }
    }
    if (total < 3) {
        cout << format("-1\n");
        return 0;
    }

    array<int, 4> dx = {-1, 1, 0, 0};
    array<int, 4> dy = {0, 0, -1, 1};
    vector st(n, vector<bool>(m, false));

    int cnt = 0;
    function<void(int, int)> dfs = [&](int x, int y) -> void {
        for (int i = 0; i < 4; i++) {
            int tx = dx[i] + x;
            int ty = dy[i] + y;

            if (tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
            if (a[tx][ty] != 1) continue;
            if (st[tx][ty] == true) continue;

            st[tx][ty] = true;
            cnt += 1;

            dfs(tx, ty);
        }
    };  // 枚举这个点出发的 连通块中 点的数量，保存在 cnt 中

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                for (cnt = 0; auto& sti : st) {
                    fill(sti.begin(), sti.end(), false);
                }
                a[i][j] = 0;
                for (int d = 0; d < 4; d++) {
                    int tx = dx[d] + i;
                    int ty = dy[d] + j;
                    if (tx < 0 or tx >= n or ty < 0 or ty >= m) continue;
                    if (a[tx][ty] != 1) continue;
                    dfs(tx, ty);
                    if (cnt > 0) {
                        a[i][j] = 1;
                        break;
                    }
                }
                // 删掉这个点之后的数量变少，说明存在宽度为一的路径
                if (cnt < total - 1) {
                    cout << format("1\n"); // 直接去除这一个点即可
                    return 0;
                }
            }
        }
    }

    // 否则说明是一坨，只需要删除一个任意边角的两个点即可
    cout << format("2\n");

    return 0;
}
/*

*/