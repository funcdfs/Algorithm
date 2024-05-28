// LINK: https://codeforces.com/contest/580/problem/C
// NAME: 580C. Kefa and Park, Codeforces - Codeforces Round #321 (Div. 2)
// CODE: https://github.com/fengwei2002, 2022.10.12-20:10:44, 2000 ms

#include <bits/stdc++.h>
using namespace std; 

const int N = 1e5 + 10; 
int n, m, ans; 
vector<int> e[N]; 
bool cats[N]; 

void dfs(int u, int fa, int cnt) {
    if (cnt > m) return; 
    bool isLeaf = true; 
    for (auto& v : e[u]) {
        if (v == fa) continue; 
        isLeaf = false; 
        dfs(v, u, cats[v] ? cnt + 1 : 0); 
    }
    ans += isLeaf; 
}

int main() {
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) cin >> cats[i]; 
    for (int i = 0; i < n - 1; i++) {
        int u = 0, v = 0; 
        cin >> u >> v; 
        e[u].push_back(v); 
        e[v].push_back(u); 
    } 
    dfs(1, 0, cats[1]); 
    cout << ans << '\n'; 
    return 0; 
}

/*
580C根节点到叶子节点路径中1的数量小于m的路径的数量


给定一棵 N 个节点的有根树（其中根节点始终为 1 号节点），点有点权，点权只有 1 和 0 两种，
求从根节点到叶子节点的路径中，有多少条路径满足：路径上最大连续点权为 1 的节点个数不超过
M。

*/