/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-16 17:00:51
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
    
    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0;
        cin >> n;
        vector<int> d(n, 0);
        for (int i = 0; i < n; i++) cin >> d[i];
        vector<int> a(n, 0);
        a[0] = d[0];
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (d[i] > 0 and a[i - 1] >= d[i]) {
                cout << -1 << '\n';
                ok = false;
                break;
            }
            a[i] = a[i - 1] + d[i];
        }
        if (ok == false) continue;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
    }
    
    return 0;
}
/*

*/