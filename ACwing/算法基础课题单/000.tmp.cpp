#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010, M = N * 2;

int n;
int head[N], e[M], ne[M], idx;  // 领接表
int ans = N;
bool st[N];

void add(int a, int b) { e[idx] = b, ne[idx] = head[a], head[a] = idx++; }

void dfs(int u) {
    st[u] = true;
    for (int i = head[u]; i != -1; i = ne[i]) {
        int j = e[i]; // 记录当前链表中的节点对应图中的编号是多少
        if (!st[j]) dfs(j);
    }
}
int main() {

    memset(head, -1, sizeof head);

    dfs(1);

    return 0;
}