#include <iostream>
using namespace std;

const int N = 100010;

int p[N];

// 注意和蹲坑法进行区分哦
int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    //将路径上的所有点的父节点都变为 x 的父节点，搜索一遍，之后的操作都是 O(1)）
    return p[x];
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;

    while (m--) {
        char op[2];
        int a, b;
        scanf("%s%d%d", op, &a, &b);
        if (*op == 'M')
            p[find(a)] = find(b);
        else {
            if (find(a) == find(b))
                puts("Yes");
            else
                puts("No");
        }
    }

    return 0;
}

// https://www.acwing.com/activity/content/code/content/1463125/