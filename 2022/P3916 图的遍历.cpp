// Problem: P3916 图的遍历
// Contest: Luogu
// url:  https://www.luogu.com.cn/problem/P3916
// date: 2022-03-31 15:34:40
// Memory Limit: 125 MB
// Time Limit:   1000 ms

#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, m; 
vector<vector<int>> g; 

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; 
    // n 个点 m 个边 
    // 求每个点可以到达的编号最大的点
    
    g.resize(n + 1); 
    
    for (int i = 0; i < m; i++) {
        int st, ed; 
        cin >> st >> ed; 
        g[ed].push_back(st); // 反向建图 
    }
    
    vector<bool> st(n + 1); 
    vector<int> ans(n + 1); 
    function<void(int, int)> dfs = [&](int x, int maxValue) {
        if (st[x] == false) {
            st[x] = true; 
            ans[x] = maxValue;
        }
        for (int i = 0; i < g[x].size(); i++) {
            if (st[g[x][i]] == false) {
                dfs(g[x][i], maxValue); 
            }
        }   
    };
    
    for (int i = n; i >= 1; i--) {
        dfs(i, i); 
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' '; 
    }
    
    cout << endl;
    
    return 0;
}