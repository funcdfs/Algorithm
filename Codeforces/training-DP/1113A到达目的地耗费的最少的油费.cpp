// URL: https://codeforces.com/contest/1113/problem/A
// NAME: A. Sasha and His Trip, Codeforces - Codeforces Round #539 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-17 14:58:52

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 0, v = 0; 
    cin >> n >> v; 
    
    if (n <= v) {
        cout << n - 1 << "\n"; 
    } else {
        cout << v + (2 + n - v) * (n - v - 1) / 2 << "\n"; 
        // 首项加末项) * 项数 / 2
        // 首项是 2 末项是 n - v 
        // 最后 v 个站点不需要加油，所以末项是 n - v 
        // 由于第一个站点已经加油了，所以项数是 n - v - 1 
    }
    
    return 0;
}


/*

1113A到达目的地耗费的最少的油费

如果 n < v 那么说明可以在最便宜的地方将所有的油加满，返回 n - 1 
否则，就需要在别的地方加油 

根据加油的价格，在越早的地方加油越好 

所以在一开始直接加满，然后每一次到新的站点就再加 1 letter 
直到最后到达第 n - v 个加油站 （再加就不礼貌了）
 
最开始的油价是 v 之后的油价是一个等差数列 所以可以直接计算 


https://codeforces.com/contest/1113/submission/168668557

*/