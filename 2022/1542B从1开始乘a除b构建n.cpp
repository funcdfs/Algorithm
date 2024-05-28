// LINK: https://codeforces.com/contest/1542/problem/B
// NAME: B. Plus and Multiply, Codeforces - Codeforces Round #729 (Div. 2)
// DATE: 2022-09-09 23:38:55, LIMIT: 512 MB, 3000 ms

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
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        int a = 0, b = 0, n = 0; 
        cin >> n >> a >> b; 
        
        cout << ([&]() -> bool {
            if (a == 1) {
                return (n - 1) % b == 0; // 3 1 2
            } 
            for (int64_t v = 1; v <= n; v *= a) {
                if ((n - v) % b == 0) {
                    return true;
                }
            } 
            return false;
        }() ? "YES" : "NO") << '\n'; 
    }
    
    return 0;
}


/*

1542B从1开始乘a除b构建n

暴力：每次可以走两条路
但是由于有一个是加法， 就可以快速的判断能不能走另一条路

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220909235742.png)

*/