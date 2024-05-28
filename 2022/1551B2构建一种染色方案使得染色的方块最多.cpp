// LINK: https://codeforces.com/contest/1551/problem/B2
// NAME: B2. Wonderful Coloring - 2, Codeforces - Codeforces Round #734 (Div. 3)
// DATE: 2022.09.18 17:13:49, LIMIT: 256 MB, 2000 ms

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
        int n = 0, k = 0; 
        cin >> n >> k;  
        vector<int> a(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        map<int, vector<int>> pos; 
        for (int i = 0; i < n; i++) {
            pos[a[i]].push_back(i); 
        } 
        /*
        将每一个元素出现的所有的下标存储起来
        */
        
        
        vector<int> ans(n); 
        vector<int> leftPart; 

        for (auto p : pos) {
            if (p.second.size() >= k) {
                /*
                如果当前字符的数量是大于 k 的，那么就将前 k 个全部染色
                */
                for (int i = 0; i < k; i++) {
                    ans[p.second[i]] = i + 1; 
                }
            } else {
                /*
                否则，将当前字符数量不够 k 的全部放到 leftPart 中 
                */
                for (int i : p.second) {
                    leftPart.push_back(i); 
                }
            }
        }
        for (int i = 0; i < leftPart.size() / k * k; i++) {
            ans[leftPart[i]] = i % k + 1; 
        }
        for (int i : ans) cout << i << ' '; 
        
        cout << '\n'; 
    }
    
    return 0;
}


/*

1551B2. Wonderful Coloring - 2
- 每一种元素要么被染色，要么不被染色
- 涂同一种颜色的元素的值互不相同
- 每一种颜色的染色数量都是相同的
- 涂颜色的数量最多

idea from: 
https://codeforces.com/contest/1551/submission/123650644

prove:
![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220918215322.png)

WHY / K * K:

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 4;
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) a[i] = i + 1; 
    
    int k = 3; 
    
    for (int i = 0; i < a.size() / k * k; i++) {
        cerr << i << ' '; 
    }
    cerr << '\n'; 
    
    for (int i = 0; i < a.size(); i++) {
        cerr << i << ' '; 
    }
    cerr << '\n'; 
    
    return 0;
}

*/