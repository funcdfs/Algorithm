// URL: https://codeforces.com/contest/1182/problem/A
// NAME: A. Filling Shapes, Codeforces - Codeforces Round #566 (Div. 2)
// LIMIT: 256 MB, 1000 ms, DATE: 2022-08-21 19:03:15


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
    cin.tie(0)->sync_with_stdio(false);
    
    int n = 0; 
    cin >> n; 
    
    unordered_map<int, long long> f;
    f[0] = 0; 
    f[1] = 0; 
    f[2] = 2; 
    for (int i = 3; i <= n; i++) {
        if (i % 2 > 0) {
            f[i] = 0; 
        } else {
            f[i] = f[i - 2] * 2;  // 分割最后一部分之后左右两侧相互独立
        }
    }
    
    cout << f[n] << "\n"; 
    
    return 0;
}


/*

1182A使用长方形填充图案的方案数量 

根据最后一步来分割方案

*/