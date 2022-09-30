// URL: https://www.acwing.com/problem/content/322/
// NAME: 能量项链, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-18 16:06:45

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 0; 
    cin >> n; 
    vector<int> w(2 * n + 2, 0); 
    for (int i = 1; i <= n; i++) {
        cin >> w[i]; 
        w[i + n] = w[i]; 
    } 
    
    vector<vector<int>> f(w.size(), vector<int>(w.size(), 0)); 
    
    for (int len = 3; len <= n + 1; len++) {
        for (int l = 1; l + len - 1 <= n * 2; l++) {
            int r = l + len - 1; 
            for (int k = l + 1; k < r; k++) {
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]); 
            }
        }
    }
    
    int ans = 0; 
    for (int l = 1; l <= n; l++) {
        ans = max(ans, f[l][l + n]); 
    } 
    
    cout << ans << endl; 

    return 0;
}


/*



*/