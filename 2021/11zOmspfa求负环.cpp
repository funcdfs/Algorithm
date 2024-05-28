#include <bits/stdc++.h>
using namespace std; 

const int N = 2010, M = 10010; 
int n, m; 
int h[N], e[M], ne[M], w[M], idx; 
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++; 
}

bool spfa() {
    vector<bool> st(n + 1, false); 
    vector<int> dist(n + 1, 1e9); 
    vector<int> cnt(n + 1, 0); 
    queue<int> que; 
    for (int i = 1; i <= n; i++) {
        st[i] = true; 
        dist[i] = 0; 
        que.push(i); 
    }
    
    while (que.size()) {
        auto t = que.front(); 
        que.pop(); 
        st[t] = false; 
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i]; 
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i]; 
                cnt[j] = cnt[t] + 1; 
                if (cnt[j] >= n) return true; 
                if (st[j] == false) {
                    que.push(j); 
                    st[j] = true; 
                }
            }
        }
    }
    return false; 
}

int main() {
    cin >> n >> m; 
    memset(h, -1, sizeof h); 
    for (int i = 0; i < m; i++) {
        int a = 0, b = 0, c = 0; 
        cin >> a >> b >> c; 
        add(a, b, c); 
    } 
    if (spfa() == true) {
        cout << "Yes\n"; 
    } else {
        cout << "No\n"; 
    } 
    return 0; 
}