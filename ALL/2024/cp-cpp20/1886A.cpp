/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1886/problem/A
 * created: 5/14/2024, 1:25:00 PM
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
    auto check = [&]() -> bool {
        // n to x, y, z;
        if (n % 3) {
            if (n < 6) return false;
            cout << format("YES\n");
            cout << format("1 2 {0}\n", n - 3);
            return true;
        } else {
            if (n < 10) return false;
            cout << format("YES\n");
            cout << format("{0} {1} {2}\n", 1, 4, n - 5);
            return true;
        }
        return false;
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