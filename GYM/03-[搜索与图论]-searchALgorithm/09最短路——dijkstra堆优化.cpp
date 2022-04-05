#include <iostream>
#include <queue> 
#include <algorithm>
#include <cstring> 

using namespace std; 

const int N = 1e5 + 10; 

int n, m; 
int h[N], w[N], e[N], ne[N], idx; 
int dist[N];
bool st[N]; 

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++; 
}


typedef pair<int, int> PII; 


int dijkstra() {
    memset(dist, 0x3f, sizeof dist); 
    dist[1] = 0; 
    
    priority_queue<
    
    if (dist[n] == 0x3f3f3f3f) {
        return -1; 
    } else {
        return dist[n]; 
    }
}

int main() {
    cin >> n >> m; 
    
    // 邻接表的初始化，将所有的表头进行初始化 
    memset(h, -1, sizeof h); 
    
    while (m--) {
        int a, b, c; 
        cin >> a >> b >> c; 
        add(a, b, c); 
        // 邻接表不对重边做重复的处理 
    }
}

