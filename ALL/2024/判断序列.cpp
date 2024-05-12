/**
 * author: https://github.com/funcdfs
 * created: 2024-04-28 22:52:10
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

    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] != 1) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
/*

*/