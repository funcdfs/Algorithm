// LINK: https://codeforces.com/contest/570/problem/B
// NAME: B. Simple Game, Codeforces - Codeforces Round #316 (Div. 2)
// DATE: 2022.09.14 16:16:23, LIMIT: 256 MB, 1000 ms

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
    
    int n = 0, m = 0; 
    cin >> n >> m; 
    int a = 0; 
    int mid = n / 2; 
    if (m > mid) {
        a = m - 1; 
    } else {
        a = m + 1; 
    }
    if (a < 1) {
        a = 1; 
    } else if (a > n) {
        a = n; 
    }
    cout << a << '\n'; 
    
    return 0;
}


/*

570Bandrewwantstowin

给 n，m (m <= n)，求一个数 a(1<=a<=n), 使得当 c 在 1 到 n 的整数中 随机取值时, |c-a| < |c-m| 成立的概率最大。

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220914170840.png)

*/