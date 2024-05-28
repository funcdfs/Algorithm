/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/893/problem/C
 * created: 5/7/2024, 9:20:50 PM	
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
    
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> c(n, 0);
    for (int i = 0; i < n; i++) cin >> c[i];
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u = 0, v = 0;
        cin >> u >> v;
        u -= 1, v -= 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int64_t ans = 0;
    vector<bool> st(n, false);
    for (int i = 0; i < n; i++) {
        if (st[i] == true) continue;
        queue<int> que;
        que.push(i);
        st[i] = true;
        int minCost = c[i];

        while (que.size()) {
            auto t = que.front();
            que.pop();
            minCost = min(minCost, c[t]);
            for (auto& x : adj[t]) {
                if (st[x] == true) continue;
                que.push(x);
                st[x] = true;
            }
        }
        ans += minCost;
    }

    cout << ans << endl;
    
    return 0;
}
/*

*/