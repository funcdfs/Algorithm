#include <bits/stdc++.h>
using namespace std; 

int main() {
    int n = 0, m = 0; 
    cin >> n >> m; 
    vector g(n + 1, vector<int>(n + 1, 1e9)); 
    for (int i = 0; i < m; i++) {
        int x = 0, y = 0, z = 0; 
        cin >> x >> y >> z; 
        g[x][y] = min(g[x][y], z); 
    } 
    function<int()> dijkstra = [&]() -> int {
        vector<bool> st(n + 1, false); 
        vector<int> dist(n + 1, 1e9); 
        dist[1] = 0; 
        for (int i = 0; i < n - 1; i++) {
            int t = -1; 
            for (int j = 1; j <= n; j++) {
                if (st[j] == false && (t == -1 || dist[t] > dist[j])) {
                    t = j; 
                }
            }
            st[t] = true; 
            for (int j = 1; j <= n; j++) {
                dist[j] = min(dist[j], dist[t] + g[t][j]); 
            }
        }
        if (dist[n] == 1e9) return -1; 
        return dist[n]; 
    };
    cout << dijkstra() << '\n'; 
    return 0; 
}