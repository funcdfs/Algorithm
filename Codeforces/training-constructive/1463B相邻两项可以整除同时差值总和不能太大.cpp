// LINK: https://codeforces.com/contest/1463/problem/B
// NAME: B. Find The Array, Codeforces - Educational Codeforces Round 100 (Rated for Div. 2)
// DATE: 2022.09.13 16:49:04, LIMIT: 256 MB, 2000 ms

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
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        for (auto& x : a) {
            int ans = 1; 
            while (abs(x - ans) * 2 > x) {
                ans *= 2; 
            }
            cout << ans << ' '; 
        } 
        cout << '\n'; 
    }
    
    return 0;
}


/*

1463B相邻两项可以整除同时差值总和不能太大


首先相邻两项可以整除，所以 1 一定是符合要求的，全构造一个 1 数组
但是这样会导致差的绝对值的和太大，如何缩小差的绝对值的和？

对于 2 来说，2*2, 2*2*2 每一个除以之前的任意次幂都是符合两两相除的

只要维持每一项都是在范围内，那么总和就在范围内

*/