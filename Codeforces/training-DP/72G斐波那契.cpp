// URL: https://codeforces.com/contest/72/problem/G
// NAME: G. Fibonacci army, Codeforces - Unknown Language Round #2
// LIMIT: 256 MB, 2000 ms
// DATE: 2022-08-18 22:32:58

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
    
    unordered_map<int, int> f;
    f[0] = 1; 
    f[1] = 1; 
    
    int n = 0; 
    cin >> n; 
    for (int i = 2; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2]; 
    } 
    cout << f[n] << endl; 

    return 0;
}


/*



*/