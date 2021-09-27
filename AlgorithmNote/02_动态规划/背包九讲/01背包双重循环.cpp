/*
 * 
 * result = max(f[n][V])
 * f[i][j];
 * 1. 不选第 i 个物品， f[i][j] = f[i - 1][j]
 * 2. 选第 i 个物品， f[i][j] = f[i - 1][j - v[i]] + w[i];
 *
 * f[i][j] = max(1, 2);
 * f[0][0] = 0;
 */

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int f[N][N];
int v[N], w[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
            }
        }
    int res = 0;
    for (int i = 0; i <= m; i++) res = max(res, f[n][i]);
    return 0;
}

// TODO 滚动数组
