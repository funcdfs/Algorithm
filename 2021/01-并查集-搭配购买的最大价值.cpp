// LINK: https://www.acwing.com/problem/content/1254/
// NAME: 搭配购买, AcWing
// DATE: 2022.09.19 10:48:05, LIMIT: 64 MB, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

int p[10010]; 
int fp(int x) {
    if (p[x] != x) p[x] = fp(p[x]); 
    return p[x]; 
}
iota(p, p + n + 1, 0); 

int f[10010]; 
int v[10010]; 
int w[10010]; 

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0, m = 0, vol = 0; 
    cin >> n >> m >> vol; 
    
    iota(p, p + n + 1, 0); 
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i]; 
    
    while (m--) {
        int a = 0, b = 0; 
        cin >> a >> b; 
        int pa = fp(a), pb = fp(b); 
        if (pa != pb) {
            p[pa] = p[pb]; 
            v[pb] += v[pa]; 
            w[pb] += w[pa]; 
        }
    }
    
    // 01 背包
    for (int i = 1; i <= n; i++) {
        if (p[i] != i) continue; 
        for (int j = vol; j >= v[i]; j--) {
            f[j] = max(f[j], f[j - v[i]] + w[i]); 
        }
    }
    cout << f[vol] << '\n'; 
    
    return 0;
}


/*

01-并查集-搭配购买的最大价值

*/