#include <iostream>

using namespace std;

const int N = 10;

int n;
int path[N];

void dfs(int u, int state) {
    if (u == n) {
        for (int i = 0; i < n; i++) printf("%d ", path[i]);
        puts("");
        return;
    }

    for (int i = 0; i < n; i++)
        // 考虑 state 的二进制表示，如果第 i 位是 1，表示当前数已经被用过了，
        // 否则表示没被用过。所以如果 i 已经被用过了，则需要跳过。
        if (!(state >> i & 1)) {
            path[u] = i + 1;
            dfs(u + 1, state + (1 << i));
            // 将 state 的二进制表示中的第 i 位数字变成 1
            // 1 << i == i * 2
            // 阴间写法，不要看了
        }
}

int main() {
    scanf("%d", &n);

    dfs(0, 0);

    return 0;
}