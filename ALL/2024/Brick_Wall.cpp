/**
 * author:  https://github.com/funcdfs
 * problem: https://www.luogu.com.cn/problem/CF1918A
 * created: 5/13/2024, 6:15:01 PM
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL /* For Local Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

auto solve() -> void {
    int n = 0, m = 0;
    cin >> n >> m;
    // the wall size is n * m
    if (n == 1 or m == 1) {
        cout << std::format("{0}\n", (n > m) ? -1 : 1);
        return;
    } else {
        cout << std::format("{0}\n", n * (m / 2));
    }
    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}
/*

*/