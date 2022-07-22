#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 510, M = 10010;

struct Edge {
    int a, b, w;
} es[M];               // 开辟结构体数组，用来存储每一条边的信息

int n, m, k;
int dist[N], last[N];  // dist 数组和 last 数组， last 数组用来记录执行更新前的 dist 数组的值

void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; i++) {        // 执行 k 次
        memcpy(last, dist, sizeof dist); // 将 dist 数组的值复制到 last 数组中
        for (int j = 0; j < m; j++) {    // 更新所有的边
            auto e = es[j];              // 用 1 到 a 的距离 加上 a 到 b 的权值更新 1 到 b 的距离
            dist[e.b] = min(dist[e.b], last[e.a] + e.w);        
        }
    }
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        es[i] = {a, b, w};
    }
    bellman_ford();
    if (dist[n] > 0x3f3f3f3f / 2) {
        cout << "impossible" << endl;
    } else {
        cout << dist[n] << endl;
    }
    
    return 0;
}