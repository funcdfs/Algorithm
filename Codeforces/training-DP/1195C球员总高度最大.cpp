// LINK: https://codeforces.com/contest/1195/problem/C
// NAME: C. Basketball Exercise, Codeforces - Codeforces Round #574 (Div. 2)
// DATE: 2022-08-25 17:28:47, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/



int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0; 
    cin >> n; 
    vector<int> a(n, 0); 
    vector<int> b(n, 0); 
    
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    } 
    for (int i = 0; i < n; i++) {
        cin >> b[i]; 
    }
    
    vector<vector<int64_t>> f(n, vector<int64_t>(2, 0)); 
    f[0][0] = a[0]; 
    f[0][1] = b[0]; 
    dbg(f[0][0], f[0][1]); 
    // init f[0] 
    
    if (n == 1) { // case n == 1
        cout << max(f[0][0], f[0][1]) << "\n"; 
        return 0;
    }
    
    if (a[1] > b[1]) {
        f[1][0] = max(f[0][0], f[0][1] + a[1]); 
        f[1][1] = f[0][0] + b[1]; 
    } else {
        f[1][0] = f[0][1] + a[1]; 
        f[1][1] = max(f[0][1], f[0][0] + b[1]); 
    }
    // init f[1] 
    dbg(f[1][0], f[1][1]); 
    
    for (int i = 2; i <= n - 1; i++) {
        f[i][0] = max({
            f[i - 1][1] + a[i], 
            f[i - 1][0], 
            f[i - 2][0] + a[i], 
            f[i - 2][1] + a[i], 
        }); 
        f[i][1] = max({
            f[i - 1][0] + b[i], 
            f[i - 1][1], 
            f[i - 2][0] + b[i], 
            f[i - 2][1] + b[i],  
        }); 
        dbg(i, f[i][0], f[i][1]); 
    } 
    
    cout << max(f[n - 1][0], f[n - 1][1]) << "\n"; 
    
    return 0;
}


/*

1195C球员总高度最大

每次选取的下标递增，求选出来的最大的总高度

f[i][x] 表示当前到达第 i 个位置获得的最大的价值 

x == 0: 这一次选取的是 a 组 
x == 1: 这一次选取的是 b 组

状态机类型 DP

*/