// URL: https://www.acwing.com/problem/content/1022/
// Problem: 潜水员, Contest: AcWing
// Mem 64 MB, Time 1000 ms
// Date: 2022-08-03 12:59:23

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

const int N = 22; 
const int M = 80; 

int n, m, k; 
int f[N][M]; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> k; 
    memset(f, 0x3f, sizeof f); 
    f[0][0] = 0; 
    
    while (k--) {
    	int v1, v2, w; 
    	cin >> v1 >> v2 >> w; 
    	for (int j = n; j >= 0; j--) {
    		for (int k = m; k >= 0; k--) {
    			f[j][k] = min(f[j][k], f[max(0, j - v1)][max(0, k - v2)] + w); 
    		}
    	}
    }
	
	cout << f[n][m] << endl; 

    return 0;
}