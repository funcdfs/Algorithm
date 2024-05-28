// LINK: https://codeforces.com/contest/1426/problem/D
// NAME: D. Non-zero Segments, Codeforces - Codeforces Round #674 (Div. 3)
// DATE: 2022.09.17 17:59:07, LIMIT: 256 MB, 2000 ms

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

    int n = 0;
    cin >> n;
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    
    int ans = 0; 
    set<int64_t> S; 
    S.insert(0); 
    
    int64_t sum = 0; 
    for (int i = 0; i < n; i++) {
        sum += a[i]; 
        
        if (S.count(sum)) { 
            ans++; 
            S.clear(); // the number before i is suitable  
        
            S = {0, a[i]}; // a[i]... as a new array part
            sum = a[i]; // new part sum is a[i]
        } else {
            S.insert(sum); 
        }
    }
    cout << ans << '\n'; 
    
    return 0;
}

/*

1426D最小插入数字数量使得没有一个子区间总和是0


数组中本来也不存在0


*/