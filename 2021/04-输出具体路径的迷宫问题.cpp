// URL: https://www.acwing.com/problem/content/1078/
// NAME: 输出具体路径的迷宫问题, AcWing
// LIMIT: 64 MB, 1000 ms, DATE: 2022-08-21 14:59:31


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
    
    int n = 0; 
    cin >> n; 
    vector<vector<int>> g(n, vector<int>(n, 0)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j]; 
        }
    } 
    
    vector<vector<pair<int, int>>> pre(n, vector<pair<int, int>>(n, {-1, -1})); 
    // 矩阵中的每个点存储一个 pair<int, int> 
    
    
    function<void(int, int)> bfs = [&](int sx, int sy) {
        queue<pair<int, int>> que; 
        que.push({sx, sy}); 
        pre[sx][sy] = {0, 0}; // not exist 
        while (que.size()) {
            auto [tx, ty] = que.front(); 
            que.pop(); 
            
            for (int i = 0; i < 4; i++) {
                int a = dx[i] + tx, b = dy[i] + ty; 
                if (a < 0 || a >= n || b < 0 || b >= n) continue; 
                if (g[a][b]) continue; 
                if (pre[a][b].first != -1) continue; // 之前被遍历过了 
                
                que.push({a, b}); 
                pre[a][b] = {tx, ty}; // 记下来时的路径 
            }
        }
    };
    
    
    bfs(n - 1, n - 1); 
    // 倒着开始搜索，将每一个点的下一步路径搜出来
    
    pair<int, int> end = {0, 0}; 
    while (1) {
        cout << end.first << ' ' << end.second << "\n"; 
        if (end.first == n - 1 && end.second == n - 1) {
            break; 
        } 
        end = pre[end.first][end.second]; 
        // 依次往后移动
    }
    
    return 0;
}


/*

2022 讯飞秋招笔试

*/