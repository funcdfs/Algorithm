/**
 * problem: https://codeforces.com/contest/1715/problem/B
 * created: https://github.com/funcdfs 5/14/2024, 11:41:41 PM
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto solve() -> void {
    int64_t n = 0, k = 0, b = 0, s = 0;
    cin >> n >> k >> b >> s;
    dbg(n, k, b, s);

    auto check = [&]() -> bool {
        int64_t minVal = b * k;
        int64_t maxVal = b * k + n * (k - 1);
        if (s < minVal or s > maxVal) return false;

        vector<int64_t> a(n, 0);
        a[0] += b * k;
        int64_t diff = s - minVal;
        for (int i = 0; i < n; i++) {
            a[i] += min(diff, k - 1);
            diff -= min(diff, k - 1);
        }
        // 等价于在平地上平分 diff，每一个的最大值为 k-1. 不会增加 beauty

        for (int i = 0; i < n; i++) {
            cout << format("{0} ", a[i]);
        }
        cout << format("\n");
        return true;
    };
    if (check() == false) {
        cout << format("-1\n");
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