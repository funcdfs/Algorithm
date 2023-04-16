/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-16 16:13:43
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
        // minimum number of moves required to obtain the array with the sum at least n
        int n = 0;
        cin >> n;
        int ans = 1e9;
        for (int x = 1; x * x <= n; x++) {
            // part1 is x*[], 
            int remain = n - x;
            ans = min(ans, x - 1 + (remain + x - 1) / x);
            // 上取整次
        }
        cout << ans << '\n';
    }
    
    return 0;
}
/*

*/