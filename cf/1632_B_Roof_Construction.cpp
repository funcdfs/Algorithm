/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-16 15:39:24
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
        int k = 1;
        while (2 * k < n) {
            k *= 2;
        }
        for (int i = k - 1; i >= 0; i--) {
            cout << i << " ";
        }
        // The value is maximum at the boundary.
        // https://www.luogu.com.cn/blog/qzhwlzy/solution-cf1632b
        for (int i = k; i < n; i++) {
            cout << i << " \n"[i == n - 1];
        }
    }
    
    return 0;
}
/*

*/