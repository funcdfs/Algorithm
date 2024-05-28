// URL: https://www.acwing.com/problem/content/190/
// NAME: 象棋中的马到达最终位置的最少步数, AcWing
// LIMIT: 64 MB, 1000 ms, DATE: 2022-08-21 15:12:20

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int n = 0, m = 0;
    cin >> m >> n; 
    
    vector<vector<char>> g(n, vector<char>(m, ' '));
    int sx = 0, sy = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'K') {
                sx = i, sy = j;
            }
        }
    }
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    dist[sx][sy] = 0; 
    
    function<int()> bfs = [&]() {
        queue<pair<int, int>> que; 
        que.push({sx, sy}); 
        
        while (que.size()) {
            auto [tx, ty] = que.front(); 
            que.pop(); 
            
            for (int i = 0; i < 8; i++) {
                int a = tx + dx[i], b = ty + dy[i]; 
                if (a < 0 || a >= n || b < 0 || b >= m) continue; 
                if (g[a][b] == '*') continue; 
                if (dist[a][b] != -1) continue; 
                if (g[a][b] == 'H') return dist[tx][ty] + 1; 
                
                dist[a][b] = dist[tx][ty] + 1; 
                que.push({a, b}); 
            }
        }  
        
        return -1; 
    };
    
    cout << bfs() << endl; 
    
    return 0;
}

/*



*/