// LINK: https://codeforces.com/contest/1365/problem/C
// NAME: C. Rotation Matching, Codeforces - Codeforces Round #648 (Div. 2)
// DATE: 2022-09-09 18:17:28, LIMIT: 256 MB, 1000 ms

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
    
    int n = 0; 
    cin >> n; 
    
    vector<int> a(n, 0); 
    vector<int> b(n, 0); 
    
    for (int i = 0; i < n; i++) cin >> a[i]; 
    for (int i = 0; i < n; i++) cin >> b[i]; 
    
    unordered_map<int, int> hsA; 
    unordered_map<int, int> hsB; 
    
    for (int i = 0; i < n; i++) hsA[a[i]] = i, hsB[b[i]] = i; 
    
    unordered_map<int, int> cnt; 
    
    for (auto& [k, v] : hsA) {
        auto v1 = hsA[k]; 
        auto v2 = hsB[k]; 
        
        int diff = (v1 - v2 + n) % n; 
        cnt[diff]++; 
    } 
    
    int maxCnt = 0; 
    for (auto& [_, v] : cnt) {
        maxCnt = max(maxCnt, v); 
    } 
    
    cout << maxCnt << '\n'; 
    
    return 0;
}


/*

1365C两个旋转密码条纹匹配的最大数量

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220909185550.png)

*/