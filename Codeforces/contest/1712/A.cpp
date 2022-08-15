// URL: https://codeforces.com/contest/1712/problem/A
// NAME: A. Wonderful Permutation, Codeforces - Codeforces Round #813 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-13 22:46:16

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        int n, k; 
        cin >> n >> k; 
        vector<int> a(n + 1, 0); 
        for (int i = 1; i <= n; i++) cin >> a[i]; 

        unordered_set<int> S; 
        for (int i = 1; i <= k; i++) {
            if (a[i] <= k) {
                S.insert(a[i]); 
            }
        } 
        
        cout << k - S.size() << endl; 
    }

    return 0;
}


/*

每次可以交换两个数字，找出最小的操作次数，使得  

p1 p2 + ... + pk 最小 

数组中的元素是属于 1 到 n 互不相同  


        int cnt = 0;
        for (int i = 1; i <= k; i++) {
            if (a[i] != i) {
                cnt++; 
                int t = a[i];    // 存储原来位置的 value 
                a[i] = i;        // 更新为正确的 value 
                a[hash[i]] = t;  // 将原来 i 对应 的 value 更新为 这个位置的 value 
                
                debug(t, hash[t], i, hash[i]);
                hash[i] = i; 
                hash[t] = hash[i]; 
            }
        } 
*/