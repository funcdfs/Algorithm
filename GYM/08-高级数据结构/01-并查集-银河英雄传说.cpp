// LINK: https://www.acwing.com/problem/content/240/
// NAME: 银河英雄传说, AcWing
// DATE: 2022.09.19 13:58:56, LIMIT: 64 MB, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

const int N = 30010; 

int m; 
int p[N]; 
int sz[N]; 
int d[N]; 

int fp(int x) {
    if (p[x] != x) {
        int root = fp(p[x]); // 找到真实根节点 
        d[x] += d[p[x]];  // 当前部分的权重 += 根节点的 d
        p[x] = root;      // 更新 p[x] 为通过 fp 函数找到的真实的 root 
    } 
    return p[x]; // 返回得到的 root 
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    cin >> m; 
    for (int i = 1; i < N; i++) {
        p[i] = i; 
        sz[i] = 1; 
        d[i] = 0; 
    } 
    
    while (m--) {
        char op; 
        int a, b; 
        cin >> op >> a >> b; 
        
        if (op == 'M') {
            int pa = fp(a), pb = fp(b); 
            if (pa != pb) {
                // 将 a 拼接到 b 的后面， 以 pb 作为根节点 
                d[pa] = sz[pb];   // 更新 d[pa] : 0-> sz[pb]
                sz[pb] += sz[pa]; // sz[pb] 将 a 的部分累加 += sz[pa]; 
                p[pa] = pb;       // 更新 p[pa]; 
            }
        } else {
            int pa = fp(a), pb = fp(b); 
            if (pa != pb) {
                cout << "-1\n"; 
            } else {
                cout << max(0, abs(d[a] - d[b]) - 1) << '\n'; 
                // 距离减一就是间隔飞船的数量
            }
        }
    }
    
    return 0;
}


/*



*/