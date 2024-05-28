#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    int n, m; 
    cin >> m >> n; 
    
    vector<int> v(n + 1, 0); 
    vector<int> w(n + 1, 0); 
    
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i]; 
    } 
    
    // vector<vector<int>> f(n + 1, vector<int>(m + 1, 0)); 
    
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         f[i][j] = f[i - 1][j]; 
    //         if (j - v[i] >= 0) {
    //             f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]); 
    //         }
    //     }
    // // }
    
    // cout << f[n][m] << endl; 
    
    vector<int> f(m, 0); 
    
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]); 
        }
    }
    
    cout << f[m] << endl; 
    
    return 0; 
}
/*
未优化空间的版本: 

f[i][j] = max(f[i - 1][j], f[i - 1][j - v[i]] + w[i]) 


f[j] = max(f[j], f[j - v[i]] + w[i]) 

f[i][j] 只和 f[i - 1][j] 和 f[i - 1][j - v[i]] 有关

计算第 i 个格子的时候， 只依赖于上一个格子的位置和上一个格子的左边位置

因此从后往前遍历，可以保证，使用前面的一个格子的时候，
前面的一个格子还没有被更新，也就是前面的格子还是之前的状态

所以逆序遍历合理
*/