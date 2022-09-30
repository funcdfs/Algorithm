// LINK: https://codeforces.com/contest/1672/problem/C
// NAME: C. Unequal Array, Codeforces - Codeforces Global Round 20
// DATE: 2022-08-23 19:16:51, LIMIT: 256 MB, 1000 ms

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
        
        int L = n; 
        int R = -1; 
        
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                L = min(L, i); 
                R = max(R, i); 
            } 
        } 
        
        if (L >= R) {
            cout << 0 << '\n'; 
        } else {
            cout << max(1, R - L - 1) << '\n';  
            // 1 2 3 
            // x x x x 
            // ans: 3 - 1 - 1
            dbg("Hi");
            dbg(a); 
            dbg(L, R); // L = 1, R = 2, the answer is 1 
        }
    }    
    
    return 0;
}


/*

1672C最少次数使得相邻数字相等的数字对的数量小于等于1

每次可以选择两个相邻的数字，一起变成一个别的数字 (0 to 1e9), 
    不可以选取最后一个数字为起始点

求使得整个序列 相邻数字相等的数字对的数量 <= 1 的最少操作次数 

------------

1 1 2 3 3 4 

1 x x 3 3 4 
1 x y y 3 4 

console.log(2)

不可以分开处理每一批连续出现的数字，所以
    实际上相当于，通过置换的操作，使得每一片都连到一起，
    从最左边第一次出现相邻相等的数字，一直链接到最右边相邻相等的数字

*/