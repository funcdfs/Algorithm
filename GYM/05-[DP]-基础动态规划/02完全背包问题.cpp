// 有 n 种物品和一个容量是 V 的背包，每种物品都有无限件可以使用

#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1010;

int n, m;
int v[N], w[N];
int f[N][N];

// 暴力解法 
int main() {
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i]; 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j]; 
            for (int k = 1; j >= v[i] * k; k++) {
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k); 
            }
        }
    }
    
    cout << f[n][m] << endl; 
    
    return 0; 
}

// 时间复杂度 O(n^2) 
// f[i][j] = f[i - 1][j] + f[i - 1][j - v[i]*1] + w[i]*1
// f[i][j - v[i]] = f[i - 1][j - v[i]*1] ... 
// f[i][j] = f[i - 1][j] , (f[i][j - v[i]] + w[i])
int main() {
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i]; 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j]; 
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i][j - v[i]] + w[i]); 
        }
    }
}

// 再用一个滚动数组 
int main() {
    cin >> n >> m; 
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i]; 
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i & 1][j] = f[(i - 1) & 1][j]; 
            if (j >= v[i]) f[i & 1][j] = max(f[i & 1][j], f[i & 1][j - v[i]] + w[i]); 
        }
    }
    
    cout << f[n & 1][m] << endl; 
    
    return 0; 
}