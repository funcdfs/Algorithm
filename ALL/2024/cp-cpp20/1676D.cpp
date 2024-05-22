/**
 * name: D. X-Sum
 * link: https://codeforces.com/contest/1676/problem/D
 * time: 2024/5/17 16:06:02 https://github.com/funcdfs
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
    vector a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    unordered_map<int, int> x, y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            x[i - j] += a[i][j];
            y[i + j] += a[i][j];
        }
    }

// TODO 对角线求和

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, x[i - j] + y[i + j] - a[i][j]);
        }
    }

    cout << format("{0}\n", ans);

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
帖木儿的祖父送给他一个棋盘，让他练习棋艺。这个棋盘是一个 $a$ 网格，有 $n$ 行和
$m$ 列，每个单元格上都写有一个**非负**整数。

帖木儿的挑战是在棋盘上放置一只主教，使主教攻击的所有单元格之和为**最大**。主教可以向对角线的所有方向攻击，而且攻击距离没有限制。请注意，主教所在的单元格也被视为受到攻击。帮助他找出他能得到的最大和。
*/