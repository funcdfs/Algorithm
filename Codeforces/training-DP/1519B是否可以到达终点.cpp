// URL: https://codeforces.com/problemset/problem/1519/B
// NAME: B. The Cake Is a Lie, Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// LIMIT: 256 MB, 2000 ms
// DATE: 2022-08-04 14:27:49

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

bool solve(int n, int m, int k) {
	if (n * m - 1 == k) {
		return true; 
	} 
	return false; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    cin >> tt; 
    
    while (tt--) {
    	int n, m, k; 
    	cin >> n >> m >> k; 
    	if (solve(n, m, k)) {
    		cout << "YES" << endl; 
    	} else {
    		cout << "NO" << endl; 
    	}
    }

    return 0;
}


/*

是否可以到达终点

1 2  3  4  5 
2 4  6  8  10
3 6  9  12 15
4 8  12 16 20
5 10 15 20 25  

f[1][1][0] = true 
*/