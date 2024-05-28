/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1851/problem/A
 * created: 5/13/2024, 7:07:19 PM
 **/

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL /* For Local Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

auto solve() -> void {
    int n = 0, m = 0, k = 0, H = 0;
    cin >> n >> m >> k >> H;
    vector<int> h(n, 0);
    for (int i = 0; i < n; i++) cin >> h[i];
    unordered_map<int, int> st;
    for (int i = 1; i <= m; i++) {
        st[H + i * k] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 1; j <= m; j++) {
            int newHeight = j * k + h[i];
            if (st.contains(newHeight)) {
                if ((newHeight - H) / k == j) {  // cannot have same ladder
                } else {
                    ok = true;
                    break;
                }
            }
        }
        if (ok == true) cnt += 1;
    }
    cout << std::format("{0}", cnt);
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