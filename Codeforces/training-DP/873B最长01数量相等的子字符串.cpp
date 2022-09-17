// LINK: https://codeforces.com/contest/873/problem/B
// NAME: B. Balanced Substring, Codeforces - Educational Codeforces Round 30
// DATE: 2022-08-23 22:01:18, LIMIT: 256 MB, 1000 ms

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
    
    int n = 0; 
    cin >> n;
    string str = ""; 
    cin >> str; 
    
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) {
        if (str[i] == '1') {
            a[i] = 1; 
        } else {
            a[i] = -1; 
        }
    }
    
    vector<int> s(n + 1, 0); 
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i - 1]; 
    }
    dbg(s); 
    
    // s[i] == s[j], max distance i -> j 
    
    unordered_map<int, int> pos; 
    int ans = 0; 
    pos[0] = 0; // if sum[x] = 0, then this point should be match with sum[0]. not nil
    
    for (int i = 1; i <= n; i++) {
        if (pos.count(s[i])) {
            ans = max(ans, i - pos[s[i]]); 
        } else {
            pos[s[i]] = i; 
        }
    } 
    
    cout << ans << "\n"; 
    
    return 0;
}


/*

873B最长01数量相等的子字符串 



*/