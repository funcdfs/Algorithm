// LINK: https://codeforces.com/contest/1540/problem/A
// NAME: 1540A. Great Graphs, Codeforces - Codeforces Round #728 (Div. 1)
// DATE: 2022.09.20 21:17:29, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/*---------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*---------------------*/



int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0; 
        cin >> n; 
        vector<int> a(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        assert(a[0] == 0); 
        auto it = a.begin(); 
        advance(it, 1); 
        sort(it, a.end()); 
        
        int64_t prevSum = 0; 
        int64_t ans = 0; 
        for (int i = 0; i < n; i++) {
            ans += prevSum - (int64_t)i * a[i]; 
            // 每添加一个新的 node 可以对之前贡献的负数边权和 
            prevSum += a[i]; // 向下走的路线之和 
        }
        
        ans += a.rbegin()[0]; 
        cout << ans << '\n'; 
        cerr << '\n'; 
    }
    
    return 0;
}


/*

1540A构造图边权之和最小

构造一个有向带权图，使得点 1 到点 i 个最短路径长度是 a[i] 
同时使得，所有边的边权之和尽可能的小 




首先可以把每一个点到每一个点的距离排序，保证路径升序
然后要使得总和最小，每一个点都向之前的所有点连一个负权边，权值为之前的点到这个点的距离

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220920232152.png)

*/