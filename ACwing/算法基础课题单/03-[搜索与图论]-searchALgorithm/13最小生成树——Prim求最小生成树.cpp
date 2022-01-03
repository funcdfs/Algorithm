// 找到集合外面距离最近的点，赋值给 t， (集合为已经在最小生成树中的点集)
// 用 t 更新其他点到 **集合** 的距离
// 把 t 加到集合当中去， st[t] = true;

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, INF = 0x3f3f3f3f;

int n, m;    // 定义点数和边的数量
int g[N][N]; // 用邻接矩阵来存图
int dist[N]; // dist[N] 存储每一个点到 最小生成树的距离
bool st[N];  // st[N] 表示某个点是否在 已经发现的最小生成树中

int prim() {
    memset(dist, 0x3f, sizeof dist);    // 初始化所有点距离答案最小生成树的距离为 0x3f3f3f3f
    
    int ans = 0;
    for (int i = 0; i < n; i++) {       // 迭代 n 次
        int t = -1;                     // 寻找不在最小生成树中，距离最小生成树最近的那一个点
        for (int j = 1; j <= n; j++) {  // 遍历所有点，距离最小的点赋值 给 t
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }
        
        if (i != 0 && dist[t] == INF) return INF;  // 如果距离最小生成树的点的最短的距离是正无穷
                                                   // 说明这个图是不连通的，直接返回正无穷就好了
        if (i != 0) ans += dist[t];                // 不是第一条边的话， ans += dist[t]
        st[t] = true;                              // 说明已经将 t 这个点加入到了最小生成树中
        
        for (int j = 1; j <= n; j++) {             // 更新所有点到最小生成树的距离
            dist[j] = min(dist[j], g[t][j]);
        }
    }
    
    return ans;
}

int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    
    int t = prim();
    
    if (t == INF) {
        cout << "impossible" << endl;
    } else {
        cout << t << endl;
    }
    
    return 0;
}