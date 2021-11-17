// n 组物品和一个容量是 v 的背包
// 每组物品有若干个，同一组的物品最多只能选择一个
// 求解将哪些物品装入背包，可使物品总体积不超过背包容量，且总价值最大。
// 输出最大价值

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110;

int n, m;
int v[N][N], w[N][N], s[N];
int f[N];

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 0; j < s[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= 0; j--) // 同 01 背包，因为要用到 i - 1 的数据，所以从大到小进行枚举 
            for (int k = 0; k < s[i]; k++)
                if (v[i][k] <= j)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);

    cout << f[m] << endl;

    return 0;
}