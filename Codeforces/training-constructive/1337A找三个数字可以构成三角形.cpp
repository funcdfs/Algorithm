// LINK: https://codeforces.com/contest/1337/problem/A
// NAME: A. Ichihime and Triangle, Codeforces - Codeforces Round #635 (Div. 2)
// DATE: 2022-09-06 10:52:01, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/



int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        int a = 0, b = 0, c = 0, d = 0; 
        cin >> a >> b >> c >> d; 
        
        int fir = b; 
        int thi = c; 
        int mid = thi - fir + 1; 
        
        if (mid >= b && mid <= c) {
            // do nothing 
        } else {
            mid = c; // 等边三角形
        }
        
        cout << fir << ' ' << mid << ' ' << thi << '\n'; 
    }
    
    return 0;
}


/*

1337A找三个数字可以构成三角形

![konng0120-README-2022-09-06-11-06-38](https://raw.githubusercontent.com/psychonaut1f/a/main/img/konng0120-README-2022-09-06-11-06-38.png)

*/