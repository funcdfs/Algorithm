/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-28 22:30:19
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
        vector<vector<int>> g(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j  =0; j < n; j++) {
                cin >> g[i][j];
            }
        }
        
    }
    
    return 0;
}
/*

*/