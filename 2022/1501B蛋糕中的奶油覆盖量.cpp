// URL: https://codeforces.com/contest/1501/problem/B
// NAME: B. Napoleon Cake, Codeforces - Codeforces Round #707 (Div. 2, based on
// Moscow Open Olympiad in Informatics) LIMIT: 256 MB, 1000 ms DATE: 2022-08-17
// 13:11:30

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

int main1() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        vector<int> c(n); 
        int k = a[n - 1];  
        for (int i = n - 1; i >= 0; i--) {
            if (k > 0 || a[i] > 0) {
                k = max(k, a[i]); 
                c[i] = 1; 
                k--; 
            }
        } 
        
        for (int i = 0; i < n; i++) {
            cout << c[i] << " \n"[i == n - 1]; 
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        int n = 0; 
        cin >> n; 
        vector<int> a(n + 1);  
        vector<int> p(n + 2); 
        for (int i = 1; i <= n; i++) {
            cin >> a[i];  
            int pre = max(i - a[i] + 1, 1); 
            p[pre]++, p[i + 1]--; 
        } 
        
        for (int i = 1; i <= n; i++) {
            p[i] += p[i - 1]; 
            if (p[i] > 0) cout << "1 "; 
            else cout << "0 "; 
        } 
        cout << "\n"; 
    }

    return 0;
}

/*

1501B蛋糕中的奶油覆盖量

从左往右进行扫描。如果遇到 a[i] > 0
就将 [max(1, i - a[i] + 1]), i] 区间中的数字都覆盖一遍
输出 1 到 n 中的每个数字是否被覆盖， 是输出 1 否则输出 0

暴力解法，参照 main1 类似于跳台阶问题 

差分

*/