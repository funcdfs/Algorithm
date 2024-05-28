#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> g;  // 存储邻接表关系

int n, m;

vector<bool> st;

void dfs(int x) {
    st[x] = true; 
    cout << x << ' '; 
    for (int i = 0; i < g[x].size(); i++) {
        if (st[g[x][i]] == false) {
            dfs(g[x][i]);
        }
    }
}

void bfs(int x) {
    fill(st.begin(), st.end(), 0);

    st[x] = true;
    queue<int> q;
    q.push(x);

    while (q.size()) {
        auto t = q.front();
        q.pop();
        cout << t << ' ';

        for (int i = 0; i < g[t].size(); i++) {
            // 遍历 t 的所有出边
            if (st[g[t][i]] == false) {
                st[g[t][i]] = true;
                q.push(g[t][i]);
            }
        }
    }
    cout << endl;
}

int main() {
    cin >> n >> m;
    // n 个点 m 条边

    g.resize(n + 1);
    st.resize(n + 1);
    
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; i++) {
        sort(g[i].begin(), g[i].end());
    }  // 按照到达的边的从小到大的顺序

    dfs(1);
    cout << endl;
    bfs(1);

    return 0;
}