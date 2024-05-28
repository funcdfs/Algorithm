// URL: https://codeforces.com/contest/580/problem/A
// NAME: A. Kefa and First Steps, Codeforces - Codeforces Round #321 (Div. 2)
// LIMIT: 256 MB, 2000 ms
// DATE: 2022-08-11 21:03:57

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
    vector<int> a(n, 0); 
    
    for (int i = 0; i < n; i++) cin >> a[i]; 
    vector<int> f(n, 0); 
    
    f[0] = 1; 
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i-1]) {
            f[i] = f[i-1] + 1; 
        } else {
            f[i] = 1; 
        }
    }
    
    dbg(a); 
    dbg(f); 
	 cout << *max_element(f.begin(), f.end()) << endl; 
    return 0;
}


/*

580A最长连续非严格递增子序列



*/