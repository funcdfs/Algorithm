/**
 * author: https://github.com/funcdfs
 * created: 2024-04-28 14:16:47
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
        int n, a, b;
        cin >> n >> a >> b;
        b = min(b, 2 * a);
        cout << n / 2 * b + n % 2 * a << endl;
    }

    return 0;
}
/*

*/