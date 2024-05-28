// URL: https://codeforces.com/contest/1359/problem/B
// NAME: B. New Theatre Square, Codeforces - Educational Codeforces Round 88 (Rated for Div. 2)
// LIMIT: 256 MB, 2000 ms, DATE: 2022-08-21 18:07:50


#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int calRowValue(vector<char>& a, int x, int y) {
    /*
    if a[i] == '*': 
        f[i] = f[i - 1] 
    if a[i] == '.' && a[i - 1] == '*': 
        f[i] = f[i - 1] + x
    if a[i] == '.' && a[i - 1] == '.': 
        f[i] = f[i - 1] + x || f[i - 2] + y
    */ 
    vector<int> f(a.size(), 0); 
    
    f[0] = a[0] == '.' ? x : 0; 
    if (a[0] == '.' && a[1] == '.') {
        f[1] = min(f[0] + x, y); 
    } else if (a[0] == '*' && a[1] == '.') {
        f[1] = f[0] + x; 
    } else {
        f[1] = f[0]; 
    }
    
    for (int i = 2; i < a.size(); i++) {
        if (a[i] == '*') {
            f[i] = f[i - 1]; 
        } else if (a[i] == '.' && a[i - 1] == '*') {
            f[i] = f[i - 1] + x;  
        } else if (a[i] == '.' && a[i - 1] == '.') {
            f[i] = min(f[i - 1] + x, f[i - 2] + y); 
        }
    } 
    dbg(f); 
    return f[a.size() - 1]; 
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int tt = 0;
    cin >> tt; 
    while (tt--) {
        int n, m, x, y; 
        cin >> n >> m >> x >> y; 
        
        vector<vector<char>> g(n, vector<char>(m, ' ')); 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> g[i][j]; 
            }
        } 
        
        // covered all . tiles 
        // use 1*1 and 1*2 
        
        int ans = 0; 
        
        for (int i = 0; i < n; i++) {
            ans += calRowValue(g[i], x, y); 
        } 
        
        cout << ans << "\n"; 
    }
    
    return 0;
}


/*

1359B使用两种木板覆盖地板的最小花费

思路: 

先使用 1*2 的将所有的空地都尽可能地塞满，然后使用 1*1 的木板来填补空隙

由于不能旋转这些木板，所以可以一行一行的来看 


线性DP
*/