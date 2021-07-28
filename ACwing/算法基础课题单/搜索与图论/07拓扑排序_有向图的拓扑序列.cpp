#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int h[N], e[N], ne[N], idx;
int d[N];  // 每个点的入度
int q[N];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool topsort() {
    int hh = 0, tt = -1;

    for (int i = 1; i <= n; i++)
        if (d[i] == 0) q[++tt] = i;
    // 将第一批入度为 0 的点放入栈中

    while (hh <= tt) {
        int t = q[hh++];
        // 弹出栈顶元素
        for (int i = h[t]; i != -1; i = ne[i]) {
            // 度栈顶元素连接的点进行遍历
            int nowValue = e[i];
            d[nowValue]--;
            // 删除一个入度之后，如果那个点的入度为 0 ，那么这个点就可以作为下一批入栈的元素
            if (d[nowValue] == 0) q[++tt] = nowValue;
        }
    }

    return tt == n - 1; 
}

int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;  // 读入的过程就可以根据每条边统计每个点的入度
    }

    if (topsort() == true) {
        for (int i = 0; i < n; i++) printf("%d ", q[i]);
        puts("");
    } else {
        puts("-1");
    }

    return 0;
}
