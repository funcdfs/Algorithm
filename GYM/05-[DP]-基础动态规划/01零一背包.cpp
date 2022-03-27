#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;        // 表示所有物品的个数
int v[N], w[N];  // v 表示体积，w 代表价值
int f[N];        // f[i][j] 代表状态

// 魔法：
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

// 暴力解法：
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i]; 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];  // 不选 i
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]); // 选 i 
        }
    }
    
    cout << f[n][m] << endl; 
    
    return 0; 
}

// 滚动数组：
int main() {
    int n, m;
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i]; 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i & 1][j] = f[(i - 1) & 1][j]; 
            if (j >= v[i]) f[i & 1][j] = max(f[i & 1][j], f[(i - 1) & 1][j - v[i]] + w[i]); 
        }
    }
    
    cout << f[n & 1][m] << endl; 
    
    return 0; 
}