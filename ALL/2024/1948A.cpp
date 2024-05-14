/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1948/problem/A
 * created: 5/14/2024, 10:24:00 AM
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
        // AAA2
        if (n % 2 == 0) {
            int idx = 0;
            int loop = n / 2;
            cout << std::format("YES\n");
            for (int i = 0; i < loop; i++) {
                if (idx == 26) idx = 0;
                cout << std::format("{0}{0}", char(idx + 'A'));
                idx += 1;
            }
            cout << std::format("\n");
            return true;
        }
        return false;
    };
    if (check() == true) {
    } else {
        cout << std::format("NO\n");
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