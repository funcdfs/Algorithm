#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int head[N], e[N], ne[N], idx; // 领接表
int d[N], q[N];             // 每个点的入度

void add(int a, int b) { e[idx] = b, ne[idx] = head[a], head[a] = idx++; }
void add(int a, int b) {
    e[idx] = b;
    ne
}
bool topsort() {
    int hh = 0, tt = -1;

    for (int i = 1; i <= n; i++)
        if (d[i] == 0) q[++tt] = i;
    // 将第一批入度为 0 的点放入队列中

    while (hh <= tt) {
        int t = q[hh++];    // 取出队列的 头元素
                            // 枚举 t 的所有出边
        for (int i = head[t]; i != -1; i = ne[i]) {
            int j = e[i];

            d[j]--;         // 删除一个入度之后，
                            // 如果 j 的入度变为 0 了，就说明现在的 j 已经修成正果了
                            // 就将 j 这个点入队
            if (d[j] == 0) q[++tt] = j;
        }
    }

    return tt == n - 1;     // 如果 tt 等于 n - 1, 那么队列中进入了 n 个点，所以他是一个有向无环图
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof head);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);

        d[b]++;             // 读入的过程就可以根据每条边统计每个点的入度
                            // 每有一条指向 b 的边，那么 b 对应的入度就加一
    }

    if (topsort() == true) {
        for (int i = 0; i < n; i++) printf("%d ", q[i]);
        puts("");
    } else {
        puts("-1");
    }

    return 0;
}
