// URL: https://atcoder.jp/contests/abc264/tasks/abc264_a
// NAME: A - "atcoder".substr(), AtCoder - freee Programming Contest 2022（AtCoder Beginner Contest 264）
// LIMIT: 1024 MB, 2000 ms
// DATE: 2022-08-17 13:26:09

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
    
    string a = "atcoder"; 
    int l = 0, r = 0; 
    cin >> l >> r; 
    l--, r--; 
    cout << a.substr(l, r - l + 1); 

    return 0;
}


/*



*/