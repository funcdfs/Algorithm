/**
 * author: https://github.com/funcdfs
 * created: 2024-04-22 14:02:32
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
    
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> v(n, 0), w(n, 0);
    for (int i = 0; i < n; i++) cin >> v[i] >> w[i];

    vector<int> f(m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = m; j - v[i] >= 0; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << f[m] << endl;
    
    return 0;
}
/*

*/