// LINK: https://codeforces.com/contest/1516/problem/B
// NAME: B. AGAGA XOOORRR, Codeforces - Codeforces Round #717 (Div. 2)
// DATE: 2022-08-25 18:21:41, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

bool canTrans(vector<int>& a) {
    int n = a.size(); 
    
    vector<int> s(n + 1, 0); 
    for (int i = 1; i <= n; i++) {
        s[i] = (s[i - 1] xor a[i - 1]);
    }
    if (s[n] == 0) return true; 
    
    for (int i = 1; i <= n; i++)  {
        for (int j = i + 1; j < n; j++) {
            // 1 -> i        i+1 -> j            j+1 -> n 
            if ((s[j] ^ s[i]) == s[i] && s[i] == (s[n] ^ s[j])) {
                return true; 
            }
        }
    }
    
    return false; 
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt;
    while (tt--) {
        int n = 0; 
        cin >> n; 
        vector<int> a(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        if (canTrans(a)) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n"; 
        }
    }
    
    return 0;
}


/*

1516B使用异或替换数组中的元素剩余两个相同元素

最多删除 n - 2 个元素，**至少剩余两个元素**

使得数组中的所有的元素相等 



*/