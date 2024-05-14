/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1927/problem/B
 * created: 5/13/2024, 5:26:50 PM	
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
    string s = "";
    array<int, 26> cnt{0};
    for (int i = 0 ;i < n; i++) {
        for (int x = 0; x < 26; x += 1) {
            if (cnt[x] == a[i]) {
                s.push_back('a' + x);
                cnt[x] += 1;
                break;
            }
        }
    }
    cout << std::format("{0}\n", s);
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