
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std; 

int n, m; 
const int N = 510; 
int g[N][N]; 
int dist[N]; 
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist); 
    dist[1] = 0; 
    
    for (int i = 0; i < n; i++) {
        int t = -1; 
        // 迭代 n 次，每一次找到当前没有确定长度的距离当中的距离的最小的一个 
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j; 
            }
        }
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        // 用 t 更新到其他点的距离 
        st[t] = true; 
        // 把 t 加入到已经确定的集合中
    }
    
    if (dist[n] == 0x3f3f3f3f) {
        return -1; 
    } else {
        return dist[n]; 
    }
}

int main() {
    memset(g, 0x3f, sizeof g); 
    
    cin >> n >> m; 
    while (m--) {
        int a, b, c; 
        cin >> a >> b >> c; 
        g[a][b] = min(g[a][b], c); 
    }
    
    int t = dijkstra(); 
    
    cout << t << endl; 
    
    return 0; 
}
