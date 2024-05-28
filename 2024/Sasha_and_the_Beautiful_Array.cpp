/**
 * author:  https://github.com/funcdfs
 * problem: https://vjudge.net/problem/CodeForces-1929A#author=GPT_zh
 * created: 5/13/2024, 5:42:17 PM
 **/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto solve() -> void {
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    int64_t ans = 0;
    ranges::sort(a);
    for (int idx = 0; auto x : a) {
        if (idx) ans += x - a[idx - 1];
        idx += 1;
    }
    cout << std::format("{0}\n", ans);
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