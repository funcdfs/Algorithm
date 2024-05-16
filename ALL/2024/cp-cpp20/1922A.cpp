/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1922/problem/A
 * created: 5/14/2024, 11:11:51 AM
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
    string a, b, c;
    cin >> a >> b >> c;
    auto check = [&]() -> bool {
        string t(n, '*');
        for_each(a.begin(), a.end(), [](char& c) { c = tolower(c); });
        for_each(b.begin(), b.end(), [](char& c) { c = tolower(c); });
        for_each(c.begin(), c.end(), [](char& c) { c = tolower(c); });
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (c[i] != a[i] and c[i] != b[i]) {
                t[i] = char(c[i] + 'A' - 'a');
                ok = true;
            }
        }
        if (ok == false) return false;
        return true;
    };
    if (check() == true) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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