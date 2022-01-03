#include <iostream>
using namespace std;

const int N = 100010;

int p[N]; // 存储每个元素的 father 是谁

int find(int x) { // 返回 x 的祖宗节点 + 路径压缩
    if (p[x] != x) p[x] = find(p[x]);
    // 将路径上的所有点的父节点都变为 x 的父节点，搜索一遍，之后的操作都是 O(1)）
    return p[x];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i; 
    // 初始化，所有节点的 p 值

    while (m--) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (*op == 'M')
            p[find(a)] = find(b); // 将 a 和 b 所在的两个集合进行合并
        else {
            if (find(a) == find(b)) // 询问编号为 a 的点和编号为 b 的点是否在同一个集合中
                puts("Yes");
            else
                puts("No");
        }
    }

    return 0;
}

// https://www.acwing.com/activity/content/code/content/1463125/