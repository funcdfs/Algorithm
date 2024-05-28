// LINK: https://codeforces.com/contest/1419/problem/D2
// NAME: 1419D2. Sage's Birthday (hard version), Codeforces - Codeforces Round #671 (Div. 2)
// DATE: 2022.09.19 15:57:21, LIMIT: 256 MB, 1000 ms

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
    cin.tie(0)->sync_with_stdio(false);
    
    int n = 0; 
    cin >> n; 
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    vector<int> b(n, 0); 
    
    sort(a.begin(), a.end()); 
    int cur = 0; 
    for (int i = 1; i < n; i += 2) {
        b[i] = a[cur++]; 
    } 
    dbg(b); 
    for (int i = 0; i < n; i += 2) {
        b[i] = a[cur++]; 
    }
    dbg(b); 
    int ans = 0; 
    for (int i = 1; i < n - 1; i++) {
        ans += b[i] < b[i - 1] && b[i] < b[i + 1]; 
    } 
    cout << ans << '\n'; 
    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1]; 
    }
    
    return 0;
}

int main2() {
    
/*
5
1 2 2 4 5


2
2 1 4 2 5
*/
    
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0; 
    cin >> n; 
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    if (n <= 2) {
        cout << "0\n"; 
        for (int i = 0; i < n; i++) {
            cout << a[i] << " \n"[i == n - 1];
        }
        return 0; 
    }
    
    sort(a.begin(), a.end()); 
    vector<int> b(n, 0); 
    b[0] = a.rbegin()[0]; 
    
    dbg(a); 
    dbg(b); 
    
    int pre = 0; 
    int suf = n - 2; 
    int idx = 1;
    while (pre < suf) {
        b[idx] = a[pre++]; 
        idx++; 
        b[idx] = a[suf--]; 
        idx++; 
    }
    b[idx] = a[pre];
    dbg(b); 
    int ans = 0; 
    for (int i = 1; i < n - 1; i++) {
        if (b[i] < b[i - 1] && b[i] < b[i + 1]) {
            ans++; 
        }
    }
    cout << ans << '\n'; 
    for (int i = 0; i < n; i++) {
        cout << b[i] << " \n"[i == n - 1]; 
    }
    return 0;
}


/*

1419D2重新排列冰激凌使得顾客购买的数量最多

顾客不买第一个，不买最后一个，对于中间的，只买严格小于左右两个冰激凌价格的 




*/