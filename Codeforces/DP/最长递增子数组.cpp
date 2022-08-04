// URL: https://codeforces.com/problemset/problem/702/A
// NAME: A. Maximum Increase, Codeforces - Educational Codeforces Round 15
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-04 13:51:31

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
    
    int n = 0; 
    cin >> n; 
    
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    vector<int> f(n, 0); 
    f[0] = 1; 
    for (int i = 1; i < n; i++) {
    	if (a[i] > a[i - 1]) {
    		f[i] = f[i - 1] + 1; 
    	} else {
    		f[i] = 1; 
    	}
    }
	cout << *max_element(f.begin(), f.end()) << endl; 
    return 0;
}


/*

最长递增子数组 

*/