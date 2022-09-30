// LINK: https://codeforces.com/contest/1555/problem/C
// NAME: C. Coin Rows, Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// DATE: 2022-09-10 09:24:05, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/



int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt; 
    
    while (tt--) {
        int m = 0; 
        cin >> m; 
        vector a(2, vector<int>(m, 0)); 
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j]; 
            }
        }
        
        vector s(2, vector<int64_t>(m + 1, 0)); 
        
        for (int i = 1; i <= m; i++) {
            s[0][i] = s[0][i - 1] + a[0][i - 1]; 
            s[1][i] = s[1][i - 1] + a[1][i - 1]; 
        } 
        
        int64_t bobScore = 1e18; 
        for (int i = 0; i <= m; i++) {
            int64_t pre = s[1][i]; 
            int64_t suf = s[0].rbegin()[0] - s[0][i + 1]; 
            bobScore = min(bobScore, max(pre, suf)); 
        } 
        
        cout << bobScore << '\n'; 
    }
    
    return 0;
}


/*

1555C向右向下走可以获得的最大的硬币的价值

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220910101855.png)

*/