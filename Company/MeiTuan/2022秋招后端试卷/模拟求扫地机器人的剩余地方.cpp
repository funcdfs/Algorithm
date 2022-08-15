#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k; 
    cin >> n >> m >> k; 
    vector<vector<int>> g(n, vector<int>(m, 0)); 
    g[0][0] = 1; 
    int cnt = n * m - 1; 
    
    int x = 0, y = 0; 
    
    while (k--) {
        char op; 
        cin >> op; 
        if (op == 'W') {
            x--; 
        } else if (op == 'A') {
            y--;
        } else if (op == 'S') {
            x++; 
        } else if (op == 'D') {
            y++; 
        } 
        if (x < 0 || x >= n || y < 0 || y >= m) {
            break; 
        }
        if (g[x][y] == 0) {
            g[x][y] = 1; 
            cnt--; 
        } 
        if (cnt == 0) {
            break; 
        }
    }  
    
    if (cnt == 0) {
        cout << "Yes" << endl; 
        cout << k + 1 << endl; 
    } else {
        cout << "No" << endl; 
        cout << cnt << endl; 
    }

    return 0;
}


/*



*/