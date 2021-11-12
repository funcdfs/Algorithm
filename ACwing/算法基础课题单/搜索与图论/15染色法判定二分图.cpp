// 一个图是 二分图，当且仅当图中不含有奇数环
// 染色法就是将一个点染成 颜色 1， 将这个点的出边染成颜色 2，
// 一条边的两个颜色只要不同，并且整个图都可以被染色，那就不会发生冲突

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010, M = 200010;

int n, m;
int h[N], e[M], ne[M], idx;
int color[N];

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool dfs(int u, int c) {
    color[u] = c;

    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!color[j]) {
            if (!dfs(j, 3 - c)) return false;
        } else if (color[j] == c)
            return false;
    }

    return true;
}

int main() {
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++)
        if (!color[i]) {
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }

    if (flag)
        puts("Yes");
    else
        puts("No");

    return 0;
}