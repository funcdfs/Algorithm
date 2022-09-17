// LINK: https://codeforces.com/contest/50/problem/A
// NAME: A. Domino piling, Codeforces - Codeforces Beta Round #47
// DATE: 2022-08-22 23:20:03, LIMIT: 256 MB, 2000 ms

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
    
    int n = 0, m = 0; 
    cin >> n >> m; 
    
    // if m % 2 == 0 or n % 2 == 0: print(n / 2) 
    if (n % 2 == 0 || m % 2 == 0) {
        cout << n * m / 2 << "\n"; 
    } else {
        cout << (n * m - 1) / 2 << "\n"; 
    }
    
    return 0;
}


/*

50A可以放置的最多的多米诺骨牌



*/