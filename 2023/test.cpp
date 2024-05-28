/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-23 16:20:13
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
    
    int n = 0, m =0;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int st, ed, w;
        cin >> st >> ed >> w;
        st -= 1, ed -= 1;
        adj[st].push_back({ed, w});
        adj[ed].push_back({st, w});
    }
    using iii = tuple<int64_t, int, int>;
    function<bool(iii&, iii&)> minPQCmp = [](iii& a, iii& b) {
        return get<0>(a) > get<0>(b);
    };
    priority_queue<iii, vector<iii>, function<bool(iii&, iii&)>> minPQ(minPQCmp);
    vector<int64_t> dist(n, - 1);
    vector<int> pre(n, -1);
    while (minPQ.size()) {
        auto [d, now, p] = minPQ.top();
        minPQ.pop();
        if (dist[now] != -1) continue;
        dist[now] = -d;
        pre[now] = p;
        for (auto& [newNode, newWeight] : adj[now]) {
            minPQ.push({d + newWeight, newNode, now});
        } 
    }
    if (dist[n - 1] == -1) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> ans(0, 0);
    for (int x = n - 1; x != -1; x = pre[x]) {
        ans.push_back(x);
    }
    for (int i = 0; i < (int)a.size(); i++) {
        cout << a[i] << " \n"[i == (int)a.size() - 1];
    }
    return 0;
}
/*

*/