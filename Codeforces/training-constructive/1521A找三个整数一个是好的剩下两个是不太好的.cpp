// LINK: https://codeforces.com/contest/1521/problem/A
// NAME: A. Nastia and Nearly Good Numbers, Codeforces - Codeforces Round #720 (Div. 2)
// DATE: 2022-09-08 14:04:41, LIMIT: 256 MB, 1000 ms

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
    
    int tt = 0; 
    cin >> tt; 
    
    while (tt--) {
        int64_t A = 0, B = 0; 
        cin >> A >> B; 
        
        if (B == 1) {
            cout << "NO\n"; 
            continue; 
        } 
        
        cout << "YES\n"; 
        if (B == 2) {
            B = 4; 
        } 
        // 当 B == 2 的时候，将 B 变为 4
        
        cout << A << ' ' << A * (B - 1) << ' ' << A * B << '\n'; 
        // A 只有 A 
        // A * (B - 1) 只有 B 
        // A * B 同时具有 AB 
    }
    
    return 0;
}


/*

1521A找三个整数一个是好的剩下两个是不太好的


x + y == z 

![konng0120-note-2022-09-08-14-31-53](https://raw.githubusercontent.com/psychonaut1f/a/main/img/konng0120-note-2022-09-08-14-31-53.png)

*/