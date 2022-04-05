// 只要不存在负环就可以使用 spfa 算法 

#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue> 

using namespace std; 

int n, m; 
const int N = 510; 
int g[N][N]; 
int dist[N]; 
bool st[N];

int spfa() {
    memset(dist, 0x3f, sizeof dist); // 初始化所有点的距离 
    dist[1] = 0; 

    queue<int> q; // 定义一个队列来存储所有待更新的点 
    q.push(1); 
    st[1] = true; // 用来表示队列中是否存在这个点，存储重复的点没有意义

    while (q.size()) {
        int t = q.front(); 
        q.pop(); 

        st[t] = false; 
        
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i]; 
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i]; 
                if (!st[j]) {
                    q.push(j); 
                    st[j] = true; 
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) {
        return -1; 
    }
    return dist[n]; 
}
    
int main() {
    memset(g, 0x3f, sizeof g); 
    
    cin >> n >> m; 
    while (m--) {
        int a, b, c; 
        cin >> a >> b >> c; 
        g[a][b] = min(g[a][b], c); 
    }
    
    int t = spfa(); 
    
    cout << t << endl; 
    
    return 0; 
}
