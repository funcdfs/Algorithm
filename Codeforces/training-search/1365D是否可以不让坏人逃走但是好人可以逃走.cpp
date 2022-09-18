// LINK: https://codeforces.com/contest/1365/problem/D
// NAME: D. Solve The Maze, Codeforces - Codeforces Round #648 (Div. 2)
// DATE: 2022.09.18 16:34:38, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

const int dx[4] = {0, 1, 0, -1}; 
const int dy[4] = {1, 0, -1, 0}; 

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0, m = 0;
        cin >> n >> m;
        vector g(n, vector<char>(m, ' '));
        int good = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j];
                if (g[i][j] == 'G') good++;
            }
        }
        
        int changedGood = 0; 
        function<void()> lockMap = [&]() {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (g[i][j] == 'B') {
                        for (int k = 0; k < 4; k++) {
                            int a = i + dx[k], b = j + dy[k]; 
                            if (a < 0 || a >= n || b < 0 || b >= m) continue; 
                            if (g[a][b] == 'G') changedGood++; 
                            if (g[a][b] != 'B') g[a][b] = '#'; 
                        }
                    }
                }
            }
        };
        
        function<bool()> trans = [&]() -> bool {
            if (g[n - 1][m - 1] == '#' && good) return false; 
            if (changedGood) return false; 
            /*
            1
            2 2
            BG
            #.
            */
            queue<pair<int, int>> que; 
            que.push({n - 1, m - 1}); 
            vector st(n, vector<bool>(m, false)); 
            st[n - 1][m - 1] = true; 
            
            while (que.size()) {
                auto [tx, ty] = que.front(); 
                que.pop(); 
                
                for (int i = 0; i < 4; i++) {
                    int a = tx + dx[i], b = ty + dy[i]; 
                    if (a < 0 || a >= n || b < 0 || b >= m) continue; 
                    if (st[a][b] == true) continue; 
                    if (g[a][b] == '#') continue; 
                    g[a][b] = 'x';
                    st[a][b] = true; 
                    que.push({a, b}); 
                }
            } 
            
            int ans = 0; 
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (g[i][j] == 'G') {
                        ans++; 
                        break; 
                    }
                }
                if (ans > 0) break; 
            } 
            
            return ans == 0; 
        }; 
        
        
        for (auto x : g) {
            dbg(x); 
        }
        
        lockMap(); 
        
        dbg("after"); 
        for (auto x : g) {
            dbg(x); 
        }
        cerr << '\n'; 
        if (trans()) {
            cout << "Yes\n"; 
        } else {
            cout << "No\n"; 
        }
    }

    return 0;
}

/*

1365D是否可以不让坏人逃走但是好人可以逃走

对于一个坏人来说，如果他的路径好人可以和一个好人重叠的话，那么就说明不可能胜利
所以直接将每一个 坏人 封锁在 一个矩形中 让他哪里都去不了

如果在这种情况下存在 好人不可以到达终点，说明这个好人一定会和某一个坏人的路径重合 


所以解法就是，进行一次全方位的封锁之后，从终点开始 bfs 走到所有可以到达的点，
最后判断一下是不是所有的 好人都被 终点的光芒照射到了

*/