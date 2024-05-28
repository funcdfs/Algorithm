/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-23 16:52:06
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
        int n = 0, x = 0;
        cin >> n >> x;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> S(n + 1, 0);
        for (int i = 0; i < n; i++) {
            S[i + 1] = S[i] + a[i];
            S[i + 1] %= x;
        }
        bool ok = false;
        for (int j = 1; j <= n; j++) {
            if (S[j] != 0) {
                ok = true;
            }
        }
        if (ok == false) {
            cout << -1 << '\n';
        } else {
            for (int i = 0; i < n; i++) {
                if (S[i] != S[n] or S[n - i] != S[0]) {
                    cout << n - i << '\n';
                    break;
                }
            }
        }
    }
    
    return 0;
}
/*

*/