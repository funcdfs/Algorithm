// URL: https://codeforces.com/contest/1451/problem/B
// NAME: B. Non-Substring Subsequence, Codeforces - Codeforces Round #685 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-12 22:20:14

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/

bool existSameSeq(string& s, int l, int r) {
    bool lif = false; 
    bool rif = false; 
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == s[l] && i < l) {
            lif = true; 
            break; 
        } else if (s[i] == s[r] && i > r) {
            rif = true; 
            break; 
        }
    } 
    
    if (lif || rif) {
        return true; 
    }
    
    return false; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        int n = 0, q = 0; 
        cin >> n >> q; 
        string s = ""; 
        cin >> s; 
        
        while (q--) {
            int l = 0, r = 0; 
            cin >> l >> r; 
            l--; 
            r--; 
            
            if (existSameSeq(s, l, r)) {
                cout << "YES" << endl;  
            } else {
                cout << "NO" << endl; 
            }
        }
    }

    return 0;
}


/*

1451B和给定区间相等的但是不连续的区间

首先 l r 是和 l r 相等的，但是 l r 是连续的 

所以可以考虑将这一段的首位向左侧移动，将末尾向右侧移动  

假设当前的首位移动到了 sx 的位置， 

则若 sx == sl 那么 sx sl+1 sr 这个序列是符合要求的 
末尾右移同理

最后只要有符合要求的，就可以输出 yes 

*/