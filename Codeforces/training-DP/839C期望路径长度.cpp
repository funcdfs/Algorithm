// LINK: https://codeforces.com/contest/839/problem/C
// NAME: C. Journey, Codeforces - Codeforces Round #428 (Div. 2)
// DATE: 2022-08-29 21:22:25, LIMIT: 256 MB, 2000 ms

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
    vector<vector<int>> g(n + 1, vector<int>(0, 0)); 
    
    for (int i = 0; i < n - 1; i++) {
        int a = 0, b = 0; 
        cin >> a >> b; 
        g[a].push_back(b); 
    } 
    
    
    
    return 0;
}


/*

TODO: 树形DP

839C期望路径长度 

一个树的性质： 
    任意两点之间的最短路径是唯一的 
        因为如果不是唯一的，那么树中就存在环 
    

*/