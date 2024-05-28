// LINK: https://www.acwing.com/problem/content/239/
// NAME: 程序自动分析, AcWing
// DATE: 2022.09.19 11:43:50, LIMIT: 64 MB, 3000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

const int N = 2e6 + 10; 
int n, m; 
int p[N]; 
unordered_map<int, int> hs; 

struct op {
    int x, y, e; 
}ops[N]; 

int get(int x) {
    if (hs.count(x) == 0) hs[x] = ++n; 
    return hs[x]; 
}

int fp(int x) {
    if (p[x] != x) p[x] = fp(p[x]); 
    return p[x]; 
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        n = 0; 
        hs.clear(); 
        cin >> m; 
        for (int i = 0; i < m; i++) {
            int x, y, e; 
            cin >> x >> y >> e; 
            ops[i] = {get(x), get(y), e}; 
        }
        for (int i = 1; i <= n; i++) p[i] = i; 
        
        for (int i = 0; i < m; i++) {
            if (ops[i].e == 1) {
                int pa = fp(ops[i].x), pb = fp(ops[i].y); 
                p[pa] = pb; 
            }
        }
        
        bool has_conflict = false; 
        for (int i = 0; i < m; i++) {
            if (ops[i].e == 0) {
                int pa = fp(ops[i].x), pb = fp(ops[i].y); 
                if (pa == pb) {
                    has_conflict = true; 
                    break; 
                }
            }
        } 
        
        if (has_conflict) cout << "NO\n"; 
        else cout << "YES\n"; 
    }
    
    return 0;
}


/*



*/