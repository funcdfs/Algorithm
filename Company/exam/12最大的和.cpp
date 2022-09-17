// LINK: https://www.acwing.com/problem/content/1053/
// NAME: 最大的和, AcWing
// DATE: 2022-08-22 21:16:44, LIMIT: 64 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

const int INF = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        int n = 0; 
        cin >> n; 
        vector<int> w(n, 0); 
        for (int i = 0; i < n; i++) cin >> w[i]; 
        
        vector<int> g(n + 1, -INF); 
        for (int i = 1, s = 0; i <= n; i++) {
            s = max(s, 0) + w[i - 1]; 
            g[i] = max(g[i - 1], s); 
        } 
        
        vector<int> h(n + 2, -INF); 
        for (int i = n, s = 0; i >= 1; i--) {
            s = max(s, 0) + w[i - 1]; 
            h[i] = max(h[i + 1], s); 
        } 
        int ans = -INF; 
        for (int i = 1; i < n; i++) {
            ans = max(ans, g[i] + h[i + 1]); 
        } 
        
        cout << ans << "\n"; 
    }
    
    return 0;
}


/*

前后缀分解

*/