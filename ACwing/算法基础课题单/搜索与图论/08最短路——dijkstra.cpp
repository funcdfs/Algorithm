#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 510;

int n, m;
int g[N][N];
int dist[N];
bool state[N];

int dijkstra(int st, int ed) {
    memset(dist, 0x3f, sizeof dist);
    dist[st] = 0;

    for (int i = 0; i < n - 1; i++) {
        int t = -1;

        for (int j = 1; j <= n; j++) {
            if (!state[j] && (t == -1 || dist[t] > dist[j])) {
                t = j;
            }
        }

        state[t] = true;

        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[ed] == 0x3f3f3f3f) return -1;
    return dist[ed];
}

int main() {
    scanf("%d%d", &n, &m);

    memset(g, 0x3f, sizeof g);

    while (m--) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }

    printf("%d\n", dijkstra(1, n));

    return 0;
}