// LINK: https://codeforces.com/contest/1367/problem/C
// NAME: C. Social Distance, Codeforces - Codeforces Round #650 (Div. 3)
// DATE: 2022-09-09 14:52:36, LIMIT: 256 MB, 2000 ms

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
        int n = 0, k = 0; 
        cin >> n >> k; 
        string s = ""; 
        cin >> s; 
        
        vector<int> a; 
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                a.push_back(i); 
            }
        } 
        
        if (a.empty()) {
            cout << (n + k) / (k + 1) << "\n"; 
        } else {
            int ans = 0; 
            
            ans += a[0] / (k + 1); 
            for (int i = 0; i < int(a.size()) - 1; i++) {
                ans += ((a[i + 1] - a[i] - 1) - k) / (k + 1); 
            } 
            ans += (n - a.back() - 1) / (k + 1);  
            
            cout << ans << '\n'; 
        } 
    }
    
    return 0;
}


/*

1367C构建固定间隔的餐厅座位的最多座位的方案

输出最多可以添加座位的数量 


任意两个相邻的 1 之间都至少存在 k 个 0 
输出最多可以将多少个 0 变成 1  

构建方式：考虑每两个元素之间可以放置多少个新的座位 

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220909174757.png)

*/