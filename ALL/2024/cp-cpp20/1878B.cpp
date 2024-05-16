/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1878/problem/B
 * created: 5/13/2024, 3:56:05 PM
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
    int idx = 1;
    for (int i = 0; i < n; i++) {
        cout << idx << ' ';
        idx += 2;
    }
    cout << endl;
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