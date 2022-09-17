// LINK: https://codeforces.com/contest/1355/problem/D
// NAME: D. Game With Array, Codeforces - Codeforces Round #643 (Div. 2)
// DATE: 2022.09.13 星期二 02:20:03 下午, LIMIT: 256 MB, 1000 ms

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
    
    int n = 0, s = 0; 
    cin >> n >> s; 
    
    if (s >= 2 * n) {
        /*
        此时假设数组是 
        2 2 2 ... s - 2(n - 1) 
    
        那么，所有的元素都是大于 1，并且不存在一个子段的和是 s - 1 
        
        petya 总是会 win
        */
        cout << "YES\n"; 
        for (int i = 0; i < n - 1; i++) {
            cout << 2 << ' '; 
        }
        cout << s - (n - 1) * 2 << '\n' << 1 << '\n'; 
    } else {
        /*
        TODO: 证明 no 的情况
        */
        cout << "NO"; 
    }
    
    
    return 0;
}


/*

1355D构造使得petya尽可能的不会输

*/