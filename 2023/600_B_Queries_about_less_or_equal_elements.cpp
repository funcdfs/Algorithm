/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-23 17:36:51
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
    
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> a(n, 0), b(m, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        int R = upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        cout << R << ' ';
    }
    
    return 0;
}
/*

*/