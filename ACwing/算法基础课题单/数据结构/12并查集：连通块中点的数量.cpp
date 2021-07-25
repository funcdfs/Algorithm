#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N], cnt[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
    // 返回每一个节点的父节点
}

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }
    // 初始化每个连通块的点数量都是 1, 编号为 1 ~ n

    while (m--) {
        string op;
        int a, b;
        cin >> op;

        if (op == "C") {
            cin >> a >> b;
            a = find(a), b = find(b);
            // 现在的 a 是 a 集合中的代表节点的值
            // b 是 b 集合中代表元素的值
            if (a != b) {
                // 如果两个集合的代表节点不在同一个集合中
                p[a] = b;
                // a 集合的代表节点的父亲值等于 b 的代表节点值
                cnt[b] += cnt[a];
                // b 代表连通块的数量 += a 代表的连通块点的数量
            }
        } else if (op == "Q1") {
            cin >> a >> b;
            if (find(a) == find(b)) puts("Yes");
            // 如果找到了 a b 的代表连通块的节点值相同，那么他们就在同一个集合中
            else
                puts("No");
        } else {
            cin >> a;
            cout << cnt[find(a)] << endl;
            // 输出 a 代表集合中节点的数量
        }
    }

    return 0;
}

// https://www.acwing.com/activity/content/code/content/1513769/