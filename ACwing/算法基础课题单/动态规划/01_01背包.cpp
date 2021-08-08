#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;        // 表示所有物品的个数
int v[N], w[N];  // v 表示体积，w 代表价值
int f[N];        // f[i][j] 代表状态

int main() {
    cin >> n >> m;  // 读入物品数量背包容量
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];  // 读入所有的物品
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         f[i][j] = f[i - 1][j]; // 集合的左边一定存在
    //         if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
    //     }
    // } 由于没有用到 f[0] 到 f[i - 2] 的值，所以可以改用一维数组存储
    // cout << f[n][m] << endl;

    for (int i = 0; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i] + w[i]]);
        }
    }
    cout << f[m] << endl;
    return 0;
}