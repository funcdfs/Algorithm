/**
 * author:  https://github.com/funcdfs
 * problem: https://www.luogu.com.cn/problem/CF1873E
 * created: 5/10/2024, 8:14:56 PM
 **/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
#define int int64_t

void solve() {
        for (int i = 0; i < n; i++) {
            if (a[i] < x) {
                ans += x - a[i];
            }
        }
        return ans <= x;
    };
    int l = 0, r = 1e10;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else
            r = mid - 1;
    }
    cout << l << endl;
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