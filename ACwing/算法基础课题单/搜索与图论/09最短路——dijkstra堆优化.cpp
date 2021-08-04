// 在一堆数字中寻找最大值/最小值的操作可以通过堆来进行优化，O(1)
// 稀疏图，但是数据范围变大了，使用领接表进行存储

#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
    // 领接表存图，w 代表权重
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;  // 小根堆
    heap.push({0, 1});                                    // 第二个是编号

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();  // 每次照当前距离最小的点

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;  // 如果之前处理过，冗余备份
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

int main() {
    cin >> n >> m;

    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << dijkstra() << endl;

    return 0;
}