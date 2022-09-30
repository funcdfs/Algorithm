// LINK: https://codeforces.com/contest/1353/problem/A
// NAME: A. Most Unstable Array, Codeforces - Codeforces Round #642 (Div. 3)
// DATE: 2022-09-02 22:35:21, LIMIT: 256 MB, 1000 ms

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
        int n = 0, m = 0; 
        cin >> n >> m; 
        
        if (n == 1) {
            cout << 0 << '\n'; 
            continue; 
        } else if (n == 2) {
            cout << m << '\n'; 
            continue; 
        } else {
            cout << m * 2 << '\n'; 
            continue; 
        }
    }
    
    return 0;
}


/*

1353A构造差值总和最大的数组

构造一个数组，数量为 n，总和为 m 

使得两个数字之间的差值的总和最大： 差值为前一个数字减去后面一个数字的绝对值 

输出这个最大的差值总和 

当 n >= 3 的时候

比如说 

1, m, 0, 0, 0 
m-1, 1, 0, 0, 0
m, 0, 0, 0, 0 

因为计算的是差值的绝对值，并且填的数字都要大于等于 0 
所以填写一个 m ，剩下全部写 0 就是最大的情况 

0, m, 0 -> 2m 
0, 0, m, 0, 0 -> 2m 

*/