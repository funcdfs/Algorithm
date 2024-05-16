/**
 * problem: https://vjudge.net/problem/SPOJ-TRIP#author=GPT_zh
 * created: https://github.com/funcdfs 2024/5/16 13:24:16
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

    string a, b;
    cin >> a >> b;

    string ans;

    // 最长公共子串
    int n = (int)a.size();
    int m = (int)b.size();
    vector<vector<char>> f(n + 1, m + 1);
    a = " " + a;
    b = "x" + b;
    for (int i = 1; i <= n; i++) {
        int maxv = 1;
        for (int j = 1; j <= n; j++) {
            f[i][j] = f[i - 1][j];
            if (a[i] == b[j]) f[i][j] = max(f[i][j], maxv);
            if (a[i] > b[j]) maxv = max(maxv, f[i - 1][j] + 1);
        }
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

*/