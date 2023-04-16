/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-15 12:00:45
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
        int k = 0, n = 0;
        cin >> k >> n;
        vector<int> ans(k, 1);
        int diff = 1;
        for (int i = 1; i < k; i++) {
            ans[i] = ans[i - 1] + diff;
            diff += 1;
            if (ans[i] > n) break;
        }
        dbg(ans);
        int maxNum = n;
        for (int i = k - 1; i >= 0; i--) {
            if (ans[i] != 1 and ans[i] < maxNum) {
                break;
            }
            ans[i] = maxNum;
            maxNum -= 1;
        }
        for (int i = 0; i < k; i++) {
            cout << ans[i] << " \n"[i == k - 1];
        }
    }
    
    return 0;
}
/*

*/