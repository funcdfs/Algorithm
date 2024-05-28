/**
 * problem: https://codeforces.com/contest/1559/problem/C
 * created: https://github.com/funcdfs 5/15/2024, 12:34:06 PM
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
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    auto check = [&]() -> bool {
        if (n == 1) {
            // 1
            if (a[0] == 1) {
                cout << format("2 1\n");
            } else if (a[0] == 0) {
                cout << format("1 2\n");
            }
            return true;
        }
        int cnt = count_if(a.begin(), a.end(), [&](auto& x) { return x == 1; });
        if (cnt == (int)a.size()) {
            // 1 1 1 1 1 1 1 1 1 1
            int now = (int)a.size() + 1;
            cout << format("{0} ", now);
            for (int i = 1; i <= n; i++) {
                cout << format("{0} ", i);
            }
            cout << format("\n");
            return true;
        }
        if (a.back() == 0) {
            // 0 0 0 0 0 0 0 0 0 0
            for (int i = 1; i <= n + 1; i++) {
                cout << format("{0} ", i);
            }
            cout << format("\n");
            return true;
        }

        for (int i = 0; i + 1 < n; i++) {
            dbg(i, i + 1);
            if (a[i] == 0 and a[i + 1] == 1) {
                int now = i + 1 + 1;
                for (int j = 1; j <= now - 1; j++) {
                    cout << format("{0} ", j);
                }
                cout << format("{0} ", n + 1);
                for (int j = now; j <= n; j++) {
                    cout << format("{0} ", j);
                }
                cout << format("\n");
                return true;
            }
        }
        return false;
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