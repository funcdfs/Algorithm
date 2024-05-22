/**
 * name: E. The Lakes
 * link: https://codeforces.com/contest/1829/problem/E
 * time: 2024/5/17 17:03:32 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

auto solve(int _case) -> void {
    dbg(_case);

    int n = 0, m = 0;
    cin >> n >> m;
    vector a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector st(n, vector<bool>(m, false));

    int64_t finalAns = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if (st[i][j] == true) continue;
            if (a[i][j] <= 0) continue;

            int64_t ans = 0;
            queue<pair<int, int>> que;
            que.push({i, j});
            st[i][j] = true;

            while (que.size()) {
                auto [tx, ty] = que.front();
                que.pop();
                ans += a[tx][ty];

                for (int d = 0; d < 4; d++) {
                    int x = tx + dx[d];
                    int y = ty + dy[d];
                    if (x < 0 or y < 0 or x >= n or y >= m) continue;
                    if (st[x][y] == true or a[x][y] <= 0) continue;
                    que.push({x, y});
                    st[x][y] = true;
                }
            }
            finalAns = max(finalAns, ans);
        }
    }
    cout << format("{0}\n", finalAns);

    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    for (int _case = 1; _case <= TT; _case++) {
        solve(_case);
    }

    return 0;
}
/*
给你一个由 $n \times m$ 个非负整数组成的 $a$ 网格。数值 $a_{i,j}$ 表示第 $i$
行和第 $j$ 列的水深。

湖泊是这样一组单元格：

- 集合中的每个单元格都有 $a_{i,j} &gt; 0$ ，并且
-
湖中任意一对单元格之间存在一条路径，该路径可以向上、向下、向左或向右移动若干次，且不会踩到有
$a_{i,j} = 0$ 的单元格。

湖泊的体积是湖中所有单元格的深度之和。

请找出网格中最大的湖泊体积。
*/