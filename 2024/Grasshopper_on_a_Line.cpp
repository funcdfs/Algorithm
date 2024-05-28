/**
 * author:  https://github.com/funcdfs
 * problem: https://www.luogu.com.cn/problem/CF1837A
 * created: 5/13/2024, 4:51:56 PM	
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
    int x = 0, k = 0;
    cin >> x >> k;
    if (x %k != 0) {
        cout << format("{0}\n{1}\n", 1, x); 
    } else {
        cout << format("2\n{0} {1}\n", 1, x - 1);
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