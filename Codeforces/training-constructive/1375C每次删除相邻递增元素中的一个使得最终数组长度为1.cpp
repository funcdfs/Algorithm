// LINK: https://codeforces.com/contest/1375/problem/C
// NAME: C. Element Extermination, Codeforces - Codeforces Global Round 9
// DATE: 2022-09-09 21:03:11, LIMIT: 256 MB, 1000 ms

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
        int n = 0; 
        cin >> n; 
        vector<int> a(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        if (a[0] < a.rbegin()[0]) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n"; 
        }
    }
    
    return 0;
}


/*

1375C每次删除相邻递增元素中的一个使得最终数组长度为1

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220909223508.png)

*/