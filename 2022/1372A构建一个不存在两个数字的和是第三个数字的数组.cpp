// LINK: https://codeforces.com/contest/1372/problem/A
// NAME: A. Omkar and Completion, Codeforces - Codeforces Round #655 (Div. 2)
// DATE: 2022-09-07 15:03:03, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/



int main1() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt; 
    unordered_map<int, int64_t> hs; 
        hs[1] = 1; 
        hs[2] = 1;
        hs[3] = 1 + 1 + 1; 
        
    for (int i = 4; i <= 1003; i++) {
        hs[i] = hs[i - 1] + hs[i - 2] + 1; 
        if (hs[i] > 1000) {
            hs[i] = 1;
        }
    }
    
    dbg(hs[1000]); 
    
    while (tt--) {
        int n = 0; 
        cin >> n; 
        
        for (int i = 1; i <= n; i++) {
            cout << hs[i] << " \n"[i == n]; 
        }
    }
    
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt; 
    
    while (tt--) {
        int n = 0; 
        cin >> n; 
        for (int i = 1; i <= n; i++) {
            cout << 1 << " \n"[i == n]; 
        }
    }
    // from jiangly: https://codeforces.com/contest/1372/submission/86994310
    
    return 0;
}
/*

1372A构建一个不存在两个数字的和是第三个数字的数组

所有的数字都是正数，并且所有数字都不超过 1000 

在 1 到 n 的范围内的任意两个数字的和不等于第三个数字




*/
