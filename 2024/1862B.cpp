/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1862/problem/B
 * created: 5/13/2024, 6:35:29 PM
 **/

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL /* For Local Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

auto solve() -> void {
    int n = 0;
    cin >> n;
    vector<int> b(n, 0);
    for (int i = 0; i < n; i++) cin >> b[i];
    // restore a[i], len(a) <= len(b) * 2

    vector<int> a(0, 0);
    a.push_back(b[0]);
    for (int i = 1; i < n; i++) {
        if (b[i] >= a.back()) {
            a.push_back(b[i]);
        } else {
            a.push_back(b[i]);
            a.push_back(b[i]);
        }
    }
    cout << std::format("{0}\n", (int)a.size());
    for (int i = 0; i < (int)a.size(); i++) {
        cout << std::format("{0} ", a[i]);
    }
    auto check = [&]() -> bool {
        vector<int> c(0, 0);
        c.push_back(a[0]);
        for (int i = 1; i < (int)a.size(); i++) {
            if (a[i] >= a[i - 1]) {
                c.push_back(a[i]);
            }
        }
        bool ok = true;
        for (int i = 0; i < (int)c.size(); i++) {
            if (c[i] != b[i]) ok = false;
        }
        if (ok == false) {
            dbg(b);
            dbg(c);
            dbg(a);
        }
        return ok;
    };
    assert(check() == true);
    cout << std::format("\n");

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