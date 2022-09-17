// LINK: https://atcoder.jp/contests/abc139/tasks/abc139_b
// NAME: B - Power Socket, AtCoder - AtCoder Beginner Contest 139
// DATE: 2022.09.13 21:59:57, LIMIT: 1024 MB, 2000 ms

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
    int left = 1; 
    while (left < b) {
        left--; // use a socket 
        left += a; // use this socket to connect a another socket 
        ans++; // the extra socket num++ 
    }
    
    cout << ans << '\n'; 
    
    return 0;
}


/*

模拟插线板扩展问题

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220913221107.png)

*/