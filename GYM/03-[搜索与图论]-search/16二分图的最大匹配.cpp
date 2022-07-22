#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int h[N], e[M], ne[M], idx; // 邻接表
int match[N];               // 每个妹子现在和哪个男生在一块
bool st[N];   // 判重，保证不重复搜一个点

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool find(int x) {
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = true;
            // 如果某个妹子没有找到对象，但是可以为她的男朋友找到对象
            // 这个妹子就空了下来，这个妹子就可以用这个男生了，
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }

    // 实在不行的话，返回的就是 false
    return false;
}

int main() {
    scanf("%d%d%d", &n1, &n2, &m);

    memset(h, -1, sizeof h);

    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int res = 0; // 存储当前匹配的数量
    for (int i = 1; i <= n1; i++) {
        memset(st, false, sizeof st); // 分析每个男生应该去找哪个妹子
        // 分析之前把所有的妹子清空，代表没有考虑过
        if (find(i)) res++; // 如果当前男生成功找到了一个每次，答案++
    }

    printf("%d\n", res);

    return 0;
}
