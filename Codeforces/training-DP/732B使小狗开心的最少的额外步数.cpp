// URL: https://codeforces.com/contest/732/problem/B
// NAME: B. Cormen — The Best Friend Of a Man, Codeforces - Codeforces Round #377 (Div. 2)
// LIMIT: 256 MB, 1000 ms
// DATE: 2022-08-18 22:38:47

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 0, k = 0; 
    cin >> n >> k; 
    
    vector<int> a(n, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    vector<int> b = a;
    int allDiff = 0;  
    for (int i = 1; i < n; i++) {
        int sum = a[i - 1] + a[i]; 
        int diff = k - sum > 0 ? k - sum : 0;
        allDiff += diff; 
        a[i] += diff; 
    }
    
    cout << allDiff << "\n"; 
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1]; 
    }
    
    return 0;
}


/*

732B使小狗开心的最少的额外步数

每一次都将填充物放到 尽可能后面

这样后面的元素就可以使用这个填充物



*/