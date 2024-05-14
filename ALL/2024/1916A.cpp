/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1916/problem/A
 * created: 5/14/2024, 1:06:52 PM
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL /* For Local Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

auto solve() -> void {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) cin >> b[i];

    auto check = [&]() -> bool {
        int64_t mul = b[0];
        for (int i = 1; i < n; i++) {
            mul *= b[i];
        }
        // make mul to 2023;
        if (mul > 2023) return false;
        if (2023 % mul) return false;
        int x = 2023 / mul;
        cout << format("YES\n");
        for (int i = 0; i < k - 1; i++) {
            cout << format("{0} ", 1);
        }
        cout << format("{0}\n", x);
        return true;
    };
    if (check() == false) {
        cout << format("NO\n");
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