// LINK: https://codeforces.com/contest/1396/problem/A
// NAME: A. Multiples of Length, Codeforces - Codeforces Round #666 (Div. 1)
// DATE: 2022.09.16 11:52:44, LIMIT: 256 MB, 1000 ms

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
    
    int64_t n = 0; 
    cin >> n; 
    vector<int64_t> a(n, 0); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    /* first step */
    if (n == 1) {
        cout << "1 1\n" << -a[0] << "\n"; 
        cout << "1 1\n" << "0\n"; 
        cout << "1 1\n" << "0\n"; 
        return 0; 
    } 
    cout << "1 1\n"; 
    cout << -a[0] << "\n"; 
    a[0] = 0; 
    
    /* second step */
    cout << "2 " << n << "\n"; 
    for (int i = 1; i < n; i++) {
        cout << a[i] * (n - 1) << ' '; 
        a[i] += a[i] * (n - 1); 
    }
    cout << '\n'; 
    
    /* thrid step */
    cout << "1 " << n << "\n"; 
    for (int i = 0; i < n; i++) {
        cout << -a[i] << ' '; 
    }
    cout << '\n'; 
    
    return 0;
}


/*

1396A三步将a变为全0

选择一个区间，然后将区间中的元素都加上 len 的任意倍，len 是这个子区间的长度

使得最终结果 a 变为全 0 


给出来一个合法的方案

x + x * (n - 1) = x * n 
x + x*n - x = x * n 

1: a1 + -a1 
2: 2 到 n 中的 ai 加上 ai*(n - 1)，现在除去第一个数字，每一个数字都是 ai * n 的大小
3: 把修改后的所有的 ai 减到 0.由于所有的数字都是 n 的倍数，所以可以直接操作

*/