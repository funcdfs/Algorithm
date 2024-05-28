/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-23 17:29:08
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
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int64_t ans = 0;
        for (int i = 0; i < n; i++) {
            int L = lower_bound(a.begin(), a.end(), l - a[i]) - a.begin();
            int R = upper_bound(a.begin(), a.end(), r - a[i]) - a.begin();
            L = max(L, i + 1);
            // the next value is greater than a[i]
            ans += max(R - L, 0);
        }
        cout << ans << '\n';
    }
    
    return 0;
}
/*

*/