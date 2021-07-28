#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
// n 条边， m 个点
using namespace std;

const int N = 100010;

int n, m;
int head[N], e[N], ne[N], idx;
int degree[N];

void add(int a, int b) { e[idx] = b, ne[idx] = head[a], head[a] = idx++; }

int bfs(int u) {
    memset(degree, -1, sizeof degree);

    queue<int> q; // BFS 通常都和队列同时存在
    degree[1] = 0;
    q.push(1);

    while (q.size()) { // while 队列不空，内套一层循环处理
        int queueTop = q.front();
        q.pop();

        for (int i = head[queueTop]; i != -1; i = ne[i]) {
            int nowValue = e[i];
            if (degree[nowValue] == -1) {
                degree[nowValue] = degree[queueTop] + 1;
                q.push(nowValue);
            }
        }
    }

    return degree[u];
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof head);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    cout << bfs(n) << endl;

    return 0;
}