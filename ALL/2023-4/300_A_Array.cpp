/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-16 15:45:46
**/

#include <bits/stdc++.h>
using namespace std;

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
    for (int i = 0; i < n; i++) cin >> a[i];

    int idx1 = -1, idx2, idx3;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            idx1 = i;
        } else if (a[i] == 0) {
            idx2 = i;
        } else if (a[i] < 0) {
            idx3 = i;
        }
    }
    if (idx1 == -1) {
        cout << 1 << ' ' << a[idx3] << '\n';
        idx1 = -1, idx2 = -1;
        for (int i = 0; i < n; i++) {
            if (idx1 == -1 and a[i] < 0) {
                idx1 = i;
            } else if (idx2 == -1 and a[i] < 0) {
                idx2 = i;
            }
        }
        dbg(a);
        dbg(idx1, idx2, idx3);
        cout << 2 << ' ' << a[idx1] << ' ' << a[idx2] << '\n';
        cout << n - 3 << ' ';
        for (int i = 0; i < n; i++) {
            if (i == idx1 or i == idx2 or i == idx3) continue;
            cout << a[i] << ' ';
        }
        cout << '\n';
        return 0;
    }
    cout << 1 << ' ' << a[idx3] << '\n';
    cout << 1 << ' ' << a[idx1] << '\n';
    cout << n - 2 << ' ';
    for (int i = 0; i < n; i++) {
        if (i == idx3 || i == idx1) continue;
        cout << a[i] << ' ';
    }
    
    return 0;
}
/*

*/