// URL: https://www.acwing.com/problem/content/428/
// NAME: 开心的金明, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-03 16:21:47

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

const int N = 30; 
const int M = 30010; 

int f[M]; 
int n, m; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	    
    cin >> m >> n; 
    
    for (int i = 1; i <= n; i++) {
    	int v, w; 
    	cin >> v >> w; 
    	w = w * v; 
    	
    	for (int j = m; j >= v; j--) {
    		f[j] = max(f[j], f[j - v] + w); 
    	}
    }
    
    cout << f[m] << endl; 

    return 0;
}