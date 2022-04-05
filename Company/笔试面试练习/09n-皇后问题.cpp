// Problem: n-皇后问题
// date: 2022-04-02 15:05:05
// Memory Limit: 64 MB
// Time Limit:   1000 ms


// #define d(a)  // https://github.com/fengwei2002/Algorithm
// #define dline // konng0120@gmail.com
// #define dendl // https://www.acwing.com/problem/content/845/

#define d(a)  cout << #a << " = " << a << ' ';
#define dline cout << " ----- " << endl;
#define dendl cout << " | \n";

#define LL long long
#define ULL unsigned long long
#define PII pair<int, int>
#define INF 0x3f3f3f3f

#include <algorithm>
#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n = 0; 
    cin >> n; 
    vector<vector<char>> g(n, vector<char>(n, 0)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.'; 
        }
    }
    
    vector<bool> col(n, false);     
    vector<bool> dg(2 * n, false);  // 长宽为 n 的矩形，2 * n 为对角线的数量  
    vector<bool> udg(2 * n, false); // 反对角线数组  
    
    function<void(int)> dfs = [&](int u) {
        if (u == n) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << g[i][j]; 
                }
                cout << endl; 
            }
            cout << endl;
            return; 
        }
        
        for (int i = 0; i < n; i++) {
            // 枚举所有列 
            if (!col[i] && !dg[u + i] && !udg[u - i + n]) {
                col[i] = true; 
                dg[u + i] = true; 
                udg[u - i + n] = true; 
                g[u][i] = 'Q'; 
                
                dfs(u + 1);  // 递归到下一层 
                
                col[i] = false; 
                dg[u + i] = false; 
                udg[u - i + n] = false; 
                g[u][i] = '.'; 
            }
        }
    };
    
    dfs(0); // 从第 0 行开始搜索
    
    return 0;
}