// URL: https://codeforces.com/problemset/problem/1180/A
// NAME: A. Alex and a Rhombus, Codeforces - Codeforces Round #569 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-04 16:34:13

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
    
    unordered_map<int, int> f; 
    
    f[1] = 1; 
    f[2] = 5; 
    
    for (int i = 3; i <= n; i++) {
    	f[i] = f[i-1] + 4 + (i - 2) * 2 * 2;  
    	// 上下两个部分的边边都多了两块，所以需要在 (i - 2) * 2 的基础上再乘 2 
    }

	cout << f[n] << endl; 

    return 0;
}


/*

计算菱形中格子的数量

1 1 
2 1+2+2 
3 5+2+2 +2+2

*/