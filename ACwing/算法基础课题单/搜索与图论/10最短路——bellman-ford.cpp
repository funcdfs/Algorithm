// 边权可能是负数，对最短路边数有限制，
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, M = 10010;
// 点数是 n 边数是 m

struct Edge {
    int a, b, w;
} e[M];

int n, m, k;
int dist[N];
int backup[N];

int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++) {
        memcpy(backup, dist, sizeof dist);
        // 只用上一次遍历的结果防止串联现象的发生，
        for (int j = 0; j < m; j++) {
            int a = e[j].a, b = e[j].b, w = e[j].w;
            dist[b] = min(dist[b], backup[a] + w);
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        e[i] = {a, b, w};
    }
    //  读入数据

    int t = bellman_ford();

    if (t == -1)
        puts("impossible");
    else
        printf("%d\n", t);

    return 0;
}