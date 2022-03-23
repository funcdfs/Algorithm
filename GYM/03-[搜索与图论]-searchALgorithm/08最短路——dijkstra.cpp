#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510;

int n, m;       // n 和 m 分别存储点的数量和边的数量
int g[N][N];    // g[N][N] 存储稠密图，对应的值等于这个边对应的权值
int dist[N];    // dist[N] 表示从一号点走到每个点的当前的最短距离是多少
bool st[N];     // st[N] 表示某个点是否已经确定了最短路线


int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;// 第一个点到第一个点的距离为 0，其他点为默认值 -1 
    
    for (int i = 0; i < n - 1; i++) {     // 迭代 n - 1 次
                                          // 找当前没有确定最短路的点 当中距离最小的那一个
        int t = -1;                       // t = -1 表示还没有确定最短距离
        for (int j = 1; j <= n; j++) {    // 遍历所有点
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;                    // 如果当前这个点没有确定最短路并且更短的话，t 更新为更短的点
            }
        }
        
        st[t] = true;                     // t 已经确定最短路，加到已经确定最短路的集合中
        
        for (int j = 1; j <= n; j++) {    // 用 t 来更新其他点的距离
            dist[j] = min(dist[j], dist[t] + g[t][j]);
                                          // 1 到 dist[t] 加上 t 到 j 的权值
        }
    }

    if (dist[n] == 0x3f3f3f3f) {
        return -1;
    } else {
        return dist[n];
    }
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    // 读入点数和边数
    
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
        // 处理重边的情况
    }
    
    cout << dijkstra() << endl;
    
    return 0;
}