#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 2010, M = 10010;

int n, m;
int head[N], w[M], e[M], ne[M], idx;
int dist[N], cnt[N]; // cnt 存储当前最短路的边数
bool st[N];          // 用来判断一个点是否在 队列中出现

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c;
    ne[idx] = head[a], head[a] = idx++;
}

bool spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        st[i] = true;
        q.push(i);
    }

    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = head[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true; // 说明 1 到 j 最少出现了 n 条边， 那么就是 n + 1 个点，抽屉原理可得必然存在环
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof head);

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    if (spfa() == true) {
        puts("Yes");
    } else {
        puts("No");
    }

    return 0;
}

// https://www.acwing.com/activity/content/code/content/2027059/