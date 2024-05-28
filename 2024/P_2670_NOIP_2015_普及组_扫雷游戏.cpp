/**
 * name: P2670 [NOIP2015 普及组] 扫雷游戏
 * link: https://www.luogu.com.cn/problem/P2670
 * time: 2024/5/16 17:34:13 https://github.com/funcdfs
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
    vector a(n + 2, vector<int>(m + 2, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == '*') {
                a[i + 1][j + 1] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                cout << "*";
            } else {
                int row1 = a[i - 1][j - 1] + a[i - 1][j] + a[i - 1][j + 1];
                int row2 = a[i][j - 1] + a[i][j + 1];
                int row3 = a[i + 1][j - 1] + a[i + 1][j] + a[i + 1][j + 1];
                cout << row1 + row2 + row3;
            }
        }
        cout << format("\n");
    }

    return 0;
}
/*

*/