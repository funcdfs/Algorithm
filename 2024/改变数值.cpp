/**
 * author: https://github.com/funcdfs
 * created: 2024-04-27 20:48:16
**/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

const int inf = numeric_limits<int32_t>::max(); 

unordered_map<int ,int> f[310];

int get(unordered_map<int, int>& s, int k) {
    if (s.count(k)) return s[k];
    return inf;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0;
    cin >> n;
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (auto& [k, v] : f[i]) {
            f[i + 1][k] = min(get(f[i + 1], k), v);
            int d = __gcd(k, a[i + 1]);
            f[i + 1][d] = min(get(f[i + 1], d), v + b[i + 1]);
        }
    }

    int ans = get(f[n], 1);
    if (ans == inf) ans = -1;
    cout << ans << endl;

    return 0;
}
/*

*/