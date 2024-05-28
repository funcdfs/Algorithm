/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1342/problem/B
 * created: 4/30/2024, 10:59:54 AM	
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
    
    int TT = 0;
    cin >> TT;
    while (TT--) {
        string t;
        cin >> t;
        for (int i = 0; i < n; i++) {
            cin >>a[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }
        auto judge = [&](int x) ->bool {
            return x == 1;
        };

        auto dfs = [&](auto self, int x) -> void {
            // 外 dfs(dfs, xxxx) 内 self(self, xxx)
            if (sum == x) {
                ans.push_back(path);
                return;
            }
            for (int i = idx; i < n; i++) {
                self(self, x, sum, path);
            }
        };
    }
    
    return 0;
}
/*

*/