/**
 * author: https://github.com/funcdfs
 * created: 2024-03-01 15:14:03
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

    int n = 5;
    int x = n / 2;
    for (int i = 0; i < n / 2; i++) {
        for (int k = 0; k < x; k++) {
            cout << ' ';
        }
        for (int k = 0; k < n - (2 * x); k++) {
            cout << '*';
        }
        for (int k = 0; k < x; k++) {
            cout << ' ';
        }
        cout << '\n';
        x = x - 1;
        if (x == 0) break;
    }

    for (int i = 0; i < n; i++) {
        cout << '*';
    }

    cout << '\n';
    x = 1;
    for (int i = 0; i < n / 2; i++) {
        for (int k = 0; k < x; k++) {
            cout << ' ';
        }
        for (int k = 0; k < n - (2 * x); k++) {
            cout << '*';
        }
        for (int k = 0; k < x; k++) {
            cout << ' ';
        }
        cout << '\n';
        x += 1;
        if (x >= (n / 2) + 1) break;
    }

    return 0;
}
/*

*/