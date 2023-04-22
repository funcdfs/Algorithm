/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-17 20:38:19
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
        for (int i = 0; i < n; i++) {
            int a = 0;
            cin >> a;
            a = abs(a);
            if (i % 2 == 0) {
                cout << a;
            } else {
                cout << -a;
            }
            cout << " \n"[i == n - 1];
        }
    }
    
    return 0;
}
/*

*/