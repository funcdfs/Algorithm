// Problem: 蛇形矩阵
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/758/
// date: 2022-03-23 13:26:22
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <iostream>
#include <vector>

using namespace std; 

int main() {
    int n, m; 
    cin >> n >> m; 
    int dx[4] = {0, 1, 0, -1}; 
    int dy[4] = {1, 0, -1, 0};
    
    int d = 0; 
    int x = 0, y = 0;
    vector<vector<int>> f(n, vector<int>(m, 0));
    
    for (int i = 1; i <= n * m; i++) {
        f[x][y] = i; 
        int a = x + dx[d]; int b = y + dy[d]; 
        if (a < 0 || a >= n || b < 0 || b >= m || f[a][b] != 0) {
            d = (d + 1) % 4; 
            a = x + dx[d]; b = y + dy[d]; 
        }
        x = a; y = b;
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << f[i][j] << ' ';
        }
        cout << endl; 
    }
    
    return 0; 
}