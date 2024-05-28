/**
 * author: https://github.com/funcdfs
 * created: 2024-04-24 12:39:32
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
    sort(a.begin(), a.end());
    int x = 1;
    while (x < n and a[x] == a[0]) {
        x += 1;
    }
    int y = x + 1;
    while (y < n and a[y] == a[x]) {
        y += 1;
    }
    int z = y + 1;
    while (z < n and a[z] == a[y]) {
        z += 1;
    }
    z -= y;
    y -= x;

    auto C = [](int a, int b) -> int64_t {
        int64_t res = 1;
        for (int i = a, j = 1; j <= b; i--, j++) res = res * i / j;
        return res;
    };
    int64_t ans = 0;
    if (x >= 3) {
        ans = C(x, 3);
    } else if (x < 3 and x + y >= 3) {
        ans = C(y, 3 - x);
    } else if (x + y < 3) {
        ans = C(z, 3 - x - y);
    }
    cout << ans << endl;

    return 0;
}
/*

*/