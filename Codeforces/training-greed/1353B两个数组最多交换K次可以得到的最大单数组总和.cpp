// LINK: https://codeforces.com/contest/1353/problem/B
// NAME: B. Two Arrays And Swaps, Codeforces - Codeforces Round #642 (Div. 3)
// DATE: 2022-08-22 23:43:04, LIMIT: 256 MB, 1000 ms

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
        vector<int> b(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        for (int i = 0; i < n; i++) cin >> b[i]; 
        
        sort(a.begin(), a.end()); 
        sort(b.begin(), b.end(), [](int& x, int& y) {
            return x > y; 
        }); 
        
        int i = 0, j = 0; 
        while (a[i] < b[j] && k > 0) {
            i++, j++; 
            k--; 
        } 
        dbg(i, j, k); 
        int sum1 = accumulate(a.begin() + i, a.end(), 0); 
        int sum2 = accumulate(b.begin(), b.begin() + j, 0); 
        
        cout << sum1 + sum2 << "\n"; 
    }
    
    return 0;
}


/*

1353B两个数组最多交换K次可以得到的最大单数组总和



*/