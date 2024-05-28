/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-18 14:45:51
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
        vector<int> b(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        // a[i] = 2^b[i]
        set<int> s(b.begin(), b.end());
        if (s.size() < n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
/*

*/