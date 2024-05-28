// LINK: https://codeforces.com/contest/1579/problem/D
// NAME: 1579D. Productive Meeting, Codeforces - Codeforces Round #744 (Div. 3)
// DATE: 2022.09.21 17:29:43, LIMIT: 256 MB, 2000 ms

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
        
        priority_queue<pair<int, int>> hp; 
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                hp.push({a[i], i}); 
            }
        }
        vector<pair<int, int>> ans; 
        while (hp.size() >= 2) {
            auto [a1, i] = hp.top(); 
            hp.pop(); 
            auto [a2, j] = hp.top(); 
            hp.pop(); 
            
            ans.push_back({i, j}); 
            a1--, a2--; 
            if (a1 > 0) {
                hp.push({a1, i}); 
            }
            if (a2 > 0) {
                hp.push({a2, j}); 
            }
        }
        cout << ans.size() << '\n'; 
        for (auto [u, v] : ans) {
            cout << u + 1 << ' ' << v + 1 << '\n'; 
            // index to the position, so + 1
        }
    }
    
    return 0;
}


/*

1579D. Productive Meeting

每次选择两个人，输出最大的匹配对数

也就是当宣布书来两个大于 0 的数字的时候，就终止会议 
可以每次选择最大的和次大的 


*/