/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-17 11:14:50
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
        int n = 0, l = 0, r = 0;
        cin >> n >> l >> r;
        // a[i] >= l, a[i] <= r
        // gcd(i, a[i]) are all distinct or report there's no solution
        vector<int> a(n + 1, 0);
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            a[i] = ((l - 1) / i + 1) * i;
            ok = ok and (a[i] <= r);
        }
        if (ok) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) {
                cout << a[i] << " \n"[i == n];
            }
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
/*
gcd(i, a[i]) <= i
because all gcd(i, a[i]) are different, then gcd(i, a[i]) == i
which means a[i] is multiple of i

to check if there is such a[i]
just check if 
    a[i] == ((l - 1) / i + 1) * i is  less then r
    (the minimum multiple of i that is strictly bigger than l - 1)
*/