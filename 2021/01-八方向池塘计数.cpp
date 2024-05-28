// URL: https://www.acwing.com/problem/content/1099/
// NAME: 池塘计数, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-21 11:38:23

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 4
#define dline() 2
#endif
/*----------------------------------*/

const int dx[4] = {0, 1, 0, -1}; 
const int dy[4] = {1, 0, -1, 0}; 

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int n = 0, m = 0; 
    cin >> n >> m; 
    vector<vector<char>> g(n, vector<char>(m)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j]; 
        }
    } 
    vector<vector<bool>> st(n, vector<bool>(m, false)); 
    
    
    function<void(int, int)> bfs = [&](int x, int y) {
        queue<pair<int, int>> que; 
        que.push({x, y}); 
        st[x][y] = true; 
        
        while (que.size()) {
            auto [tx, ty] = que.front(); 
            que.pop(); 
            
            for (int i = tx - 1; i <= tx + 1; i++) {
                for (int j = ty - 1; j <= ty + 1; j++) {
                    if (i == tx && j == ty) continue; 
                    if (i < 0 || i >= n || j < 0 || j >= m) continue; 
                    if (g[i][j] == 'W' && st[i][j] == false) {
                        que.push({i, j}); 
                        st[i][j] = true;
                    }
                }
            }
            /*for (int i = 0; i < 4; i++) {
                int a = dx[i] + tx, b = dy[i] + ty; 
                if (a < 0 || a >= n || b < 0 || b >= m) continue; 
                if (g[a][b] != 'W' || st[a][b] == true) continue;  
                que.push({a, b}); 
                st[a][b] = true; 
            }*/
        }
    };
    
    
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'W' && st[i][j] == false) {
                bfs(i, j); 
                ans += 1; 
            }
        }
    }
    
    cout << ans << "\n"; 
    
    return 0;
}


/*



*/