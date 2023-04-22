/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-14 18:53:26
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
        // contains non-negativee numbers 
        // divide each element by k, round it down, and sum up the resulting value
        // give k, then make the beauty equal to b, and the sum of element is equal to s
        int n = 0, x = 0, s = 0, q = 0;
        cin >> n >> x >> s >> q;
        vector<int> a(n, 0);
        a[0] = x * s;
        q -= x * s;
        if (q < 0) {
            cout << "-1\n";
        } else {
            for (int i = 0; i < n; i++) {
                int now = min(x - 1, q);
                a[i] += now;
                q -= now;
            }
            
        }
    }
    
    return 0;
}
/*

*/