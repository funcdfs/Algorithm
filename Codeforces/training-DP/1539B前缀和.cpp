// URL: https://codeforces.com/contest/1539/problem/B
// NAME: B. Love Song, Codeforces - Codeforces Round #727 (Div. 2)
// LIMIT: 256 MB, 2000 ms
// DATE: 2022-08-09 23:11:37

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
    
    int n = 0, q = 0; 
    cin >> n >> q; 
    
    string s; 
    cin >> s; 
    
    vector<int> sum(n + 1, 0); 
    for (int i = 1; i <= n; i++) {
    	sum[i] = sum[i - 1] + s[i - 1] - 'a' + 1;
    }
    
    while (q--) {
    	int l = 0, r = 0; 
    	cin >> l >> r;  
    	
    	cout << sum[r] - sum[l - 1] << endl; 
    }

    return 0;
}


/*



*/