/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1971/problem/F
 * created: 5/10/2024, 11:47:26 PM
 **/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    while (TT--) {
        int r = 0;
        cin >> r;
        int ans = 0;
        // for (int x = 0; x <= r + 3; x++) {
        //     for (int y = 0; y <= r + 3; y++) {
        //         if (x * x + y * y >= r * r and x * x + y * y < (r + 1) * (r + 1)) {
        //             ans += 1;
        //         }
        //     }
        // }
        // cout << ans * 4 - 4 << endl;

        // 斜着枚举
        int st = -3; int ed = 0;
        int stx = 0, sty = r + 3;
        while (stx <= r + 3) {
            for (int i = st; i <= ed; i++) {
                int x = stx + i;
                int y = sty;
                if (x * x + y * y >= r * r and x * x + y * y < (r + 1) * (r + 1)) {
                    ans += 1;
                }
            }
            st += 1, ed += 1;
            sty -= 1;
            stx += 1;
        }
        cout << ans << endl;
    }

    return 0;
}
/*

*/