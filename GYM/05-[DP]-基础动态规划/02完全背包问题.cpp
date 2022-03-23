// 有 n 种物品和一个容量是 V 的背包，每种物品都有无限件可以使用

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N];

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= m; j++) 
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    // i 正序遍历， j 正序遍历，
    cout << f[m] << endl;

    return 0;
}
