// LINK: https://codeforces.com/contest/1270/problem/C
// NAME: 1270C. Make Good, Codeforces - Good Bye 2019
// DATE: 2022.09.21 14:07:29, LIMIT: 256 MB, 2000 ms

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
        int64_t sum = 0; 
        int x = 0; 
        for (int i = 0; i < n; i++) {
            int a; 
            cin >> a; 
            sum += a; 
            x ^= a; 
        } 
        cout << 2 << '\n'; 
        cout << x << ' ' << sum + x << '\n'; 
        
        // 放一个 x 之后，异或和就是 0 了
        // 0 异或一个数字，的结果就是这个数字 
        // 因为要满足 sum(a) = 2 * xor
        // 所以 0 + sum + x) * 2 == 2sum + 2x;
        // 而 sum 变为了 sum + x + sum + x == 2sum + 2x;  
    }
    
    return 0;
}


/*

1270C最多添加三个数字使得数组good

放三个数字所有值异或起来乘2等于所有数字相加



*/