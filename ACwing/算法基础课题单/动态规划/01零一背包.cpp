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
        cin >> v[i] >> w[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            // i 正序遍历， j 逆序遍历
            f[j] = max(f[j], f[j - v[i] + w[i]]);
        }
    }
    cout << f[m] << endl;
    return 0;
}

