// LINK: https://codeforces.com/contest/732/problem/A
// NAME: A. Buy a Shovel, Codeforces - Codeforces Round #377 (Div. 2)
// DATE: 2022-08-31 12:18:11, LIMIT: 256 MB, 1000 ms

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
    
    int k = 0, r = 0; 
    cin >> k >> r; 
    
    // k 是铲子的价格， r 是剩下的那一个金币的大小  
    
    int cnt = 1; 
    for (int i = 1; i <= 10; i++) {
        if (((i * k) % 10) == r || ((i * k) % 10) == 0) {
            cnt = i; 
            break; 
        } 
        cnt = i; 
    } 
    
    cout << cnt << '\n'; 
    
    return 0;
}


/*

732A最少购买多少个铲子 

*/