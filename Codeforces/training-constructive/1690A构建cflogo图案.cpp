// LINK: https://codeforces.com/contest/1690/problem/A
// NAME: A. Print a Pedestal (Codeforces logo?), Codeforces - Codeforces Round #797 (Div. 3)
// DATE: 2022-09-08 13:31:19, LIMIT: 256 MB, 1000 ms

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
        int n = 0; 
        cin >> n; 
        vector<int> a(3, 0); 
        
        int avg = n / 3; 
        if (n % 3 == 0) {
            a[0] = n / 3; 
            a[1] = n / 3 + 1; 
            a[2] = n / 3 - 1; 
        } else {
            if (n % 3 == 1) {
                n = n - 1; 
                a[0] = n / 3; 
                a[1] = n / 3 + 1; 
                a[2] = n / 3 - 1; 
                a[1]++;
            } else if (n % 3 == 2) {
                n++; 
                a[0] = n / 3; 
                a[1] = n / 3 + 1; 
                a[2] = n / 3 - 1; 
                a[2] --; 
            }
        }
        
        debug(a); 
        
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " \n"[i == a.size() - 1]; 
        }
    }
    
    return 0;
}


/*

1690A构建cflogo图案

同时最高的山峰尽可能的低 



*/