// LINK: https://www.acwing.com/problem/content/1074/
// NAME: 树的最长路径, AcWing
// CODE: https://github.com/fengwei2002, 2022.10.08-20:59:31, 1000 ms
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std; 

const int N = 10010, M = N * 2; 
int n; 
int h[N], e[M], w[M], ne[M], idx; 
int ans; 
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++; 
} 

int dfs(int u, int father) {
    int dist = 0; 
    int d1 = 0, d2 = 0; 
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i]; 
        if (j == father) continue; 
        int d = dfs(j, u) + w[i]; 
        dist = max(dist, d); 
        
        if (d >= d1) {
            d2 = d1; 
            d1 = d; 
        } else if (d > d2) {
            d2 = d; 
        }
    }
    ans = max(ans, d1 + d2); 
    return dist; 
}

int main() {
    cin >> n; 
    memset(h, -1, sizeof h); 
    for (int i = 0; i < n - 1; i++) {
        int a = 0, b = 0, w = 0; 
        cin >> a >> b >> w; 
        add(a, b, w); 
        add(b, a, w); 
    }
    dfs(1, -1); 
    cout << ans << '\n'; 
    return 0; 
}