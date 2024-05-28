/**
 * author: https://github.com/funcdfs
 * created: 2024-04-28 14:06:31
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
    int q = 0;
    cin >> q; 
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    while (q--) {
        int x = 0;
        cin >> x;
        auto left = lower_bound(a.begin(), a.end(), x);
        auto right = upper_bound(a.begin(), a.end(), x);
        if (*left != x) {
            cout << -1 << ' ' << -1 << endl;
        } else {
            cout << distance(a.begin(), left) << ' ' << distance(a.begin(), right) - 1 << endl;
        }
    }
    
    return 0;
}
/*

*/