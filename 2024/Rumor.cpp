/**
 * author:  https://github.com/funcdfs
 * problem: https://www.luogu.com.cn/problem/CF893C
 * created: 5/7/2024, 8:51:08 PM
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

    // 并查集，根底部的值是这一堆中元素价格的最小值。

    vector<int> c(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u = 0, v = 0;
        cin >> u >> v;
        u -= 1, v -= 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);
    int64_t ans = 0;

    for (int i = 0; i < n; i++) {
        if (vis[i] == true) continue;
        queue<int> que;
        que.push(i);
        vis[i] = true;

        int minCost = c[i];

        while (que.size()) {
            auto x = que.front();
            que.pop();
            minCost = min(minCost, c[x]);
            for (auto& y : adj[x]) {
                if (vis[y] == false) {
                    vis[y] = true;
                    que.push(y);
                }
            }
        }

        ans += minCost;
    }

    cout << ans << endl;

    return 0;
}
/*

*/