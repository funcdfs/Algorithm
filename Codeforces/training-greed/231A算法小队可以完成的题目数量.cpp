// LINK: https://codeforces.com/contest/231/problem/A
// NAME: A. Team, Codeforces - Codeforces Round #143 (Div. 2)
// DATE: 2022-08-22 23:08:20, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/



int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0; 
    cin >> n; 
    vector<int> w(n, 1); 
    
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0, c = 0; 
        cin >> a >> b >> c;  
        w[i] = w[i] * pow(10, a + b + c); 
    }
    debug(w); 
    
    int ans = 0; 
    for (int i = 0; i < n; i++) {
        if (w[i] >= 100) {
            ans += 1; 
        }
    } 
    cout << ans << "\n"; 
    
    return 0;
}


/*

231A算法小队可以完成的题目数量

*/