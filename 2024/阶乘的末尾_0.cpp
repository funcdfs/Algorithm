/**
 * author: https://github.com/funcdfs
 * created: 2024-04-09 22:36:19
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
    
    int ans = 0;
    int n = 0;
    cin >> n;
    while (n > 0) {
        ans += n / 5;
        n /= 5;
    }
    cout << ans << endl;
    
    return 0;
}
/*

*/