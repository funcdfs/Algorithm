// URL: https://www.acwing.com/problem/content/175/
// NAME: 每个点到最近的1的距离, AcWing
// LIMIT: 64 MB, 1000 ms, DATE: 2022-08-21 17:29:03


#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/

const int dx[] = {0, 1, 0, -1}; 
const int dy[] = {1, 0, -1, 0}; 

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n = 0, m = 0; 
    cin >> n >> m; 
    vector<vector<char>> g(n, vector<char>(m, ' ')); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j]; 
        }
    } 
    
    queue<pair<int, int>> que; 
    vector<vector<int>> d(n, vector<int>(m, -1)); 
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '1') {
                que.push({i, j}); 
                d[i][j] = 0; 
            }
        }
    } 
    
    while (que.size()) {
        auto [tx, ty] = que.front();
        que.pop(); 
        
        for (int i = 0; i < 4; i++) {
            int a = dx[i] + tx, b = dy[i] + ty; 
            if (a < 0 || a >= n || b < 0 || b >= m) continue; 
            if (d[a][b] != -1) continue; 
            d[a][b] = d[tx][ty] + 1; 
            que.push({a, b}); 
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << d[i][j] << " \n"[j == m - 1]; 
        }
    }
    
    return 0;
}


/*



*/