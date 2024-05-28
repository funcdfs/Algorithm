/**
 * problem: https://codeforces.com/contest/1922/problem/B
 * created: https://github.com/funcdfs 5/15/2024, 2:04:08 PM
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto C = [](int64_t a, int64_t b) -> int64_t {
    int64_t res = 1;
    for (int64_t i = a, j = 1; j <= b; i--, j++) res = res * i / j;
    return res;
};

auto solve() -> void {
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> hs;
    for (int i = 0; i < n; i++) hs[a[i]] += 1;

    int64_t ans = 0;
    int64_t sum = 0;

    for (auto& it : hs) {
        int64_t cnt = it.second;
        if (cnt >= 3) {
            ans += C(cnt, 3);
        }
        if (cnt >= 2) {
            ans += C(cnt, 2) * sum;
        }
        sum += cnt;
    }

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