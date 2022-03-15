// Problem: 1387：搭配购买(buy)
// Contest: SSOIER
// URL: http://ybt.ssoier.cn:8088/problem_show.php?pid=1387
// date: 2022-03-12 14:58:26
// Memory Limit: 65 MB
// Time Limit: 1000 ms

/* https://github.com/fengwei2002/algorithm */

#define INF 0x3f3f3f3f
#define LL long long
#define PII pair<int, int>

// for debug:

// #define d(a)  // cout << #a << " = " << a << ' ';
// #define dline // cout << " ----- " << endl;
// #define dendl // cout << " | \n";

#define d(a) cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int n, m, vol;
int v[N], w[N];
int p[N];
int f[N];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 住在一个连通块中的云朵都需要一次购买
    // 所以可以使用并查集进行维护
    // 并查集统计信息的时候，统计记录每个连通块的总价值
    // 然后把每一块看做一个物品，接下来就是 01 背包问题了

    // 总体积 和 总价值，都绑定到根节点

    cin >> n >> m >> vol;

    for (int i = 1; i <= n; i++) {
        p[i] = i;  // 初始化并查集数组
    }

    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }

    while (m--) {
        // 读入 m 个边的关系
        int a, b;
        cin >> a >> b;
        int pa = find(a);
        int pb = find(b);

        if (pa != pb) {
            v[pb] += v[pa];
            w[pb] += w[pa];
            p[pa] = p[pb];
        }  // 不相等的时候，进行合并操作，并查集更新的同时根节点信息更新
    }

    // 01 背包
    for (int i = 1; i <= n; i++) {
        if (p[i] == i) {
            // 只考虑是根节点的值
            for (int j = vol; j >= v[i]; j--) {
                f[j] = max(f[j], f[j - v[i]] + w[i]);
            }
        }
    }
    cout << f[vol] << endl;

    return 0;
}