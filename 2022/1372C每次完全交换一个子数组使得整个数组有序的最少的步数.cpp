// LINK: https://codeforces.com/contest/1372/problem/C
// NAME: C. Omkar and Baseball, Codeforces - Codeforces Round #655 (Div. 2)
// DATE: 2022-09-12 17:39:05, LIMIT: 256 MB, 2000 ms

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
        int n = 0; 
        cin >> n; 
        vector<int> a(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i], a[i]--; 
        
        if (is_sorted(a.begin(), a.end())) {
            cout << 0 << '\n'; 
            continue; 
        } 
        
        int l = 0, r = n - 1; 
        while (l < n) {
            if (a[l] == l) {
                l++; 
            } else {
                break; 
            }
        } 
        while (r >= 0) {
            if (a[r] == r) {
                r--; 
            } else {
                break; 
            }
        } 
        
        bool ok = false; 
        for (int i = l; i <= r; i++) {
            if (a[i] == i) {
                ok = true; 
                break; 
            } 
        }
        
        if (ok == true) {
            cout << 2 << '\n'; 
        } else {
            cout << 1 << '\n';
        }
    }
    
    return 0;
}


/*

1372C每次完全交换一个子数组使得整个数组有序的最少的步数

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220912184514.png)

*/