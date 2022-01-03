#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 100010;

int n, m;
int head[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = head[a], head[a] = idx++;
}

int spfa() {
    memset(dist, 0x3f, sizeof dist);  // 初始化所有点的距离
    dist[1] = 0;

    queue<int> q;    // 定义一个队列存储所有等待更新的点
    q.push(1);       // 把一号点放到队列里面去，
    st[1] = true;    // st 代表当前的点是不是在队列中，防止队列中存储重复的点

    while (q.size()) {
        int t = q.front();
        q.pop();   // 取出队头的元素
        st[t] = false;

        for (int i = head[t]; i != -1; i = ne[i]) { // 更新 t 的所有邻边
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {                      // 如果 j 不在队列中，加到队列中
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return dist[n];
}

int main() {
    memset(head, -1, sizeof head);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int t = spfa();

    if (t == 0x3f3f3f3f) {
        cout << "impossible" << endl;
    } else {
        cout << t << endl;
    }
    
    return 0;
}
