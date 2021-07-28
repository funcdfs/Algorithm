#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010, M = N * 2;

int n;
int head[N], e[M], ne[M], idx;
int ans = N;
bool nodeState[N];

void add(int a, int b) { e[idx] = b, ne[idx] = head[a], head[a] = idx++; }

int dfs(int u) {
    nodeState[u] = true;

    int nodeSum = 0, maxTreeSize = 0;

    for (int i = head[u]; i != -1; i = ne[i]) {
        int nowValue = e[i];
        if (nodeState[nowValue] == false) {
            int subTreeSum = dfs(nowValue);
            nodeSum += subTreeSum;

            maxTreeSize = max(maxTreeSize, subTreeSum);
        }
    }

    maxTreeSize = max(maxTreeSize, n - nodeSum - 1);

    ans = min(ans, maxTreeSize);

    return nodeSum + 1;
}

int main() {
    cin >> n;

    memset(head, -1, sizeof head);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}