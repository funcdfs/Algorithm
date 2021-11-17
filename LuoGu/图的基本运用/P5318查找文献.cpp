#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

// 给出一个图，可能存在重边和自环，设计一种方法，实现不重复，不遗漏的遍历图中所有的点

// 用领接表存储图
const int N = 1e5 + 10, M = 1e6 + 10;
int n, m; // 存储点数和边数
int head[N], e[M], ne[M], idx;

// head[N] 存储每一个点的所有出边
// e[M]  存储每一个边的起点值
// ne[M] 存储每一个边的结尾值

bool dfsSt[N], bfsSt[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = head[a], head[a] = idx++;
}


// 有很多篇文章可以参阅，请先看编号较小的那篇(因此你可能需要先排序)。


int q[N];
void bfs() {
    int hh = 0, tt = -1;
    q[++tt] = 1;

    while (hh <= tt) {
        int t = q[hh++];

        for (int i = head[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (bfsSt[j] == false) {
                q[++tt] = j;
                cout << j << ' ';
            }
        }
    }
}


int main() {
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    // dfs();
    bfs();

    return 0;
}
