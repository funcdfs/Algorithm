/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1971/problem/A
 * created: 5/10/2024, 10:41:55 PM
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
        int x, y;
        cin >> x >> y;
        cout << min(x, y) << ' ' << max(x, y) << endl;
    }

    return 0;
}
/*

*/