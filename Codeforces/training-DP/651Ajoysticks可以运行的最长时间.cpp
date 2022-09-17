// LINK: https://codeforces.com/contest/651/problem/A
// NAME: A. Joysticks, Codeforces - Codeforces Round #345 (Div. 2)
// DATE: 2022-08-27 10:32:36, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/



int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int a = 0, b = 0; 
    cin >> a >> b; 
    
    int ans = 0; 
    while (a > 0 && b > 0) {
        if (a <= b) {
            a += 1; 
            b -= 2; 
        } else {
            b += 1; 
            a -= 2; 
        }
        if (a < 0 || b < 0) break; 
        
        dbg(a, b); 
        ans++; 
    }
    
    cout << ans << "\n"; 
    
    return 0;
}


/*

651Ajoysticks可以运行的最长时间

连接充电器:   +1
不连接充电器: -2



*/