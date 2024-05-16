/**
 * author: https://github.com/funcdfs
 * created: 2024-04-13 13:14:34
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
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    ranges::for_each(a, [](int& x) {x += 1;});
    for (int i = 0; i < n; i++) {
        cout << a[i]  << ' ';
    }
    return 0;
}
/*

*/