/**
 * problem: https://codeforces.com/contest/1859/problem/B
 * created: https://github.com/funcdfs 5/14/2024, 10:46:39 PM
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto solve() -> void {
    int n = 0;
    cin >> n;
    vector a(n, vector<int>(0, 0));
    for (int i = 0; i < n; i++) {
        int m = 0;
        cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; j++) cin >> a[i][j];
        ranges::sort(a[i]);
    }

    for (int i = 0; i < n; i++) {
        dbg(a[i]);
    }
    dbg("HI");
    int minIdx = 0;
    int minVal = a[0][1];
    vector<int> minVec(n, 0);
    for (int i = 0; i < n; i++) {
        if (a[i][1] < minVal) {
            minIdx = i;
            minVal = a[i][1];
        }
        minVec[i] = a[i][0];
    }
    int64_t ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == minIdx) continue;
        ans += a[i][1];
    }
    ans += *min_element(minVec.begin(), minVec.end());
    cout << format("{0}\n", ans);
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