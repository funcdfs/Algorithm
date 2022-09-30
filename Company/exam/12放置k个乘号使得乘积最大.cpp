// LINK: https://www.acwing.com/problem/content/1028/
// NAME: 乘积最大, AcWing
// DATE: 2022-08-22 21:43:41, LIMIT: 64 MB, 1000 ms

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
    
    int n = 0, k = 0; 
    cin >> n >> k; 
    
    string num = ""; 
    cin >> num; 
    
    
    function<int64_t(int, int, int, int)> dfs = [&](int u, int s, int v, int p) {
        if (u == n) {
            if (s == k + 1) return int64_t(p); 
            return int64_t(-1);  
        } 
        
        v = v * 10 + num[u] - '0'; // 将当前的这个数字叠加到 v 中
        return max(dfs(u + 1, s, v, p), dfs(u + 1, s + 1, 0, p * v)); 
        // 1: u 位置后面不加乘号,          2: u 位置的后面加乘号
    };
    
    
    cout << dfs(0, 0, 0, 1) << "\n"; 
    // 枚举到第几位了，当前存在几个数字段落，现在的乘积是多少
    
    return 0;
}


/*

放置k个乘号使得乘积最大

*/