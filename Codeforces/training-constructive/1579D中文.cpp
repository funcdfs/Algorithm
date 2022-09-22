// LINK: https://codeforces.com/contest/1579/problem/D
// NAME: 1579D. Productive Meeting, Codeforces - Codeforces Round #744 (Div. 3)
// DATE: 2022.09.21 17:02:49, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
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
        int n = 0; 
        cin >> n; 
        vector<int> a(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        for (auto x : a) cerr << x << ' '; cerr << '\n'; 
    }
    
    return 0;
}


/*

1579D中文

*/