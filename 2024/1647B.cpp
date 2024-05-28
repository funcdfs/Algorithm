/**
 * problem: https://codeforces.com/contest/1647/problem/B
 * created: https://github.com/funcdfs 2024/5/16 13:33:50
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto solve(int _case) -> void {
    dbg(_case);

    int n = 0, m = 0;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m, ' '));
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            a[i][j] = g[i][j] - '0';
        }
    }
    auto check = [&]() -> bool {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m - 1; j++) {
                int sum = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
                if (sum == 3) {
                    return false;
                }
            }
        }
        return true;
    };
    if (check()) {
        cout << format("YES\n");
    } else {
        cout << format("NO\n");
    }

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

给定一个棋盘，其中只包含 0 和 1
所有由数字 1 组成的最大矩形（不在其他矩形中的矩形）

判断是否不存在相交的最大矩形

100
011
011  YES

110
111
110  NO

01111 YES

11111
01010
01000
01000 NO

11
00
11 YES


*/