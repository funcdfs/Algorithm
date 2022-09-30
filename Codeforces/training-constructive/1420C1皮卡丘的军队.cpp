// LINK: https://codeforces.com/contest/1420/problem/C1
// NAME: C1. Pokémon Army (easy version), Codeforces - Codeforces Round #672 (Div. 2)
// DATE: 2022.09.14 11:01:46, LIMIT: 256 MB, 2000 ms

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
        int n = 0, q = 0; 
        cin >> n >> q; 
        vector<int> a(n, 0); 
        for (int i = 0; i < n; i++) {
            cin >> a[i]; 
        }
        assert(q == 0); 
        
        int64_t ans = 0; 
        for (int i = 0; i < n; i++) {
            int cur = a[i]; 
            int nxt = (i == n - 1 ? 0 : a[i + 1]); 
            ans += max(cur - nxt, 0); 
            
            if (cur - nxt > 0) {
                dbg(a[i], cur, nxt);
            }
        }
        
        cout << ans << '\n'; 
        dbg("End");
    }
    
    return 0;
}


/*

1420C1皮卡丘的军队

把所有 前一个数字减后一个数字是正数的统计起来

最后一个数字和 0 进行比较

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220914134257.png)


idea from: 
https://codeforces.com/contest/1420/submission/93721995

*/