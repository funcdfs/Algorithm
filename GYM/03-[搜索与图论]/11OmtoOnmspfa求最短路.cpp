#include <bits/stdc++.h>
using namespace std; 

const int N = 1e5 + 10; 
int n, m; 
int h[N], w[N], e[N], ne[N], idx; 
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++; 
} 
int spfa() {
    vector<int> dist(n + 1, 1e9); 
    vector<bool> st(n + 1, false); 
    dist[1] = 0; 
    queue<int> que; 
    que.push(1); 
    st[1] = true; 
    
    while (que.size()) {
        auto t = que.front(); 
        que.pop(); 
        st[t] = false; 
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i]; 
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i]; 
                if (st[j] == false) {
                    que.push(j); 
                    st[j] = true; 
                }
            }
        }
    }
    return dist[n]; 
}
int main() {
    cin >> n >> m; 
    memset(h, -1, sizeof h); 
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0, c = 0; 
        cin >> a >> b >> c; 
        add(a, b, c); 
    } 
    int t = spfa(); 
    if (t == 1e9) {
        cout << "impossible" << '\n'; 
    } else {
        cout << t << '\n';
    } 
    return 0; 
}