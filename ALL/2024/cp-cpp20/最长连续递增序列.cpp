/**
 * author: https://github.com/funcdfs
 * created: 2024-04-09 22:15:09
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
    
    int n = 0;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i < n; i++) cin >> a[i];

    vector<int> f(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            f[i] = f[i - 1] + 1;
        }
    }
    cout << *max_element(f.begin(), f.end()) << endl;

    return 0;
}
/*

*/