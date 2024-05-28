#include <iostream>
using namespace std;

const int N = 50010;

int n, m;
int p[N], d[N];

int find(int x) {
    if (p[x] != x) {
        int t = find(p[x]);
        d[x] += d[p[x]];  // 注意这三句话额先后顺序
        // 因为有递归函数的执行，所以 不能写成
        // d[x] += d[p[x]]; p[x] = find(p[x]);
        p[x] = t;
    }
    return p[x];
}

int main() {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) p[i] = i;

    int res = 0;
    while (m--) {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);

        if (x > n || y > n) res++;
        // 如果 x 或者 y 大于 n 的话，假话个数加一
        else {
            int px = find(x), py = find(y);
            // px 是 x 的根节点, py 是 y 节点的根节点
            if (t == 1) {
                if (px == py && (d[x] - d[y]) % 3 != 0) res++;
                // 如果 x y 在同一颗树上面，那么就可以根据度数差值是否相同来判断
                else if (px != py) {
                    // 如果不在同一颗树上面的时候, 将他们合并为同一颗树
                    p[px] = py;
                    // x 的根节点的父亲变为 y 的根节点
                    d[px] = d[y] - d[x];
                    // 合并之后 d[x] + ? 要和 d[y] 进行对比
                }
            } else {
                // 否则表示 x 吃 y
                if (px == py && (d[x] - d[y] - 1) % 3 != 0)
                    res++;  // 如果在同一颗树上面的话，等于 0 才是真话
                else if (px != py) {
                    // 如果不在同一颗树上面的话，合并到同一颗树
                    p[px] = py;
                    d[px] = d[y] + 1 - d[x];
                    // 注意这里 x 到 y 的距离要多加 1 因为 x 吃 y
                }
            }
        }
    }

    printf("%d\n", res);

    return 0;
}
// https://www.acwing.com/activity/content/code/content/1514523/