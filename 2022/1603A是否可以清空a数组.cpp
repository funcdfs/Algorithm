// LINK: https://codeforces.com/contest/1603/problem/A
// NAME: A. Di-visible Confusion, Codeforces - Codeforces Round #752 (Div. 1)
// DATE: 2022.09.14 13:40:42, LIMIT: 256 MB, 1000 ms

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
        
        function<bool()> trans = [&]() -> bool {
            for (int i = 0; i < n; i++) {
                bool ok = false; 
                // a[1] is the first element 
                for (int j = 2; j <= i + 2; j++) {
                    if (a[i] % j) {
                        ok = true; 
                        break; 
                    }
                }
                dbg(a[i], ok); 
                if (ok == false) {
                    return false; 
                }
            }
            return true;
        }; 
        
        if (trans()) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n"; 
        }
    }
    
    return 0;
}


/*

1603A是否可以清空a数组

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220914143106.png)

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int ans = 0; 
    
    for (int i = 0; i < numeric_limits<int>::max(); i++) {
        for (int j = 2; j <= i + 1; j++) {
            if (i % j) {
                ans = max(ans, j); 
                break; 
            }
        }
    } 
    
    cout << ans << '\n'; 
    // 23
    // 程序在测试点 #1 上运行了 42787ms 后终止了
    
    return 0;
}

22*n

*/