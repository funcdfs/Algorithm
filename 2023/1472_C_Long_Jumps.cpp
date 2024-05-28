/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-23 15:38:53
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
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> dp(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = a[i];
            int j = i + a[i];
            if (j < n) {
                dp[i] += dp[j];
            }
        }
        cout << *max_element(dp.begin(), dp.end());
        cout << '\n';
    }
    
    return 0;
}
/*
定义 dp[i] 为在将 i 作为起始位置的时候，可以得到的最大的分数
*/