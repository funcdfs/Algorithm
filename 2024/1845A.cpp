/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1845/problem/A
 * created: 5/14/2024, 11:51:43 AM
 **/
#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL /* For Local Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

auto solve() -> void {
    int n = 0, k = 0, x = 0;
    cin >> n >> k >> x;

    if (k > 1 and x > 1) {
        cout << format("YES\n");
        cout << format("{0}\n", n);
        for (int i = 0; i < n; i++) {
            cout << format("{0} ", 1);
        }
        cout << format("\n");
        return;
    }

    if (k > 1 and n % 2 == 0) {
        cout << format("YES\n");
        cout << format("{0}\n", n / 2);
        for (int i = 0; i < n / 2; i++) {
            cout << format("{0} ", 2);
        }
        cout << format("\n");
        return;
    }

    if (k > 2 and n >= 3) {
        cout << format("YES\n");
        cout << format("{0}\n", n / 2);
        for (int i = 0; i < n / 2 - 1; i++) {
            cout << format("{0} ", 2);
        }
        cout << format("{0}\n", 3);
        return;
    }

    cout << format("NO\n");

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