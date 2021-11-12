// 在一堆数字中寻找最大值/最小值的操作可以通过堆来进行优化，O(1)
// 稀疏图，但是数据范围变大了，使用领接表进行存储
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e6 + 10;

int n, m;
int head[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c;
    ne[idx] = head[a], head[a] = idx++;
} // 使用领接表存图， w 代表权重

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    priority_queue<PII, vector<PII>, greater<PII>> heap; // 定义小根堆
    heap.push({0, 1}); // heap 中放入 第一个点，第一个点到自己的距离是 0

    while (heap.size()) {
        auto t = heap.top();
        heap.pop(); // 每次找出当前距离最小的那一个点
        
        int f = t.second, distance = t.first;
        if (st[f] == true) continue;
        st[f] = true;
        
        for (int i = head[f]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[f] + w[i]) {
                dist[j] = dist[f] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    
    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


int main() {
    cin >> n >> m;
    memset(head, -1, sizeof head);
    while (m--) {
        int a = 0, b = 0, c = 0;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    
    cout << dijkstra() << endl;
    
    return 0;
}