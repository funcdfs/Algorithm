// Problem: 蛇形矩阵
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/758/
// date: 2022-03-23 13:26:22
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {
    int n, m; 
    cin >> n >> m; 
    
    vector<vector<int>> g(n, vector<int>(m, 0)); 
    
    int x = 0, y = 0, d = 0; 
    int dx[4] = {0, 1, 0, -1}; 
    int dy[4] = {1, 0, -1, 0}; 
    
    for (int i = 1; i <= n * m; i++) {
        g[x][y] = i; 
        int a = dx[d] + x; 
        int b = dy[d] + y;
        if (a < 0 || a >= n || b < 0 || b >= m || g[a][b] != 0) {
            d = (d + 1) % 4; 
            a = x + dx[d]; 
            b = y + dy[d]; 
        } 
        x = a; 
        y = b; 
    } 
    
    for (auto x : g) {
        for (auto y : x) {
            cout << y << ' '; 
        } 
        cout << endl; 
    }
    
    return 0; 
}