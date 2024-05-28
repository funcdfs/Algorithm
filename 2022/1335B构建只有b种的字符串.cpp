// LINK: https://codeforces.com/contest/1335/problem/B
// NAME: B. Construct the String, Codeforces - Codeforces Round #634 (Div. 3)
// DATE: 2022-09-04 22:59:13, LIMIT: 256 MB, 2000 ms

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
        int n = 0, a = 0, b = 0; 
        cin >> n >> a >> b; 
        
        int repeat = n / b; 
        string path = ""; 
        for (int i = 1; i <= repeat; i++) {
            for (int j = 0; j < b; j++) {
                path.push_back('a' + j); 
            } 
        } 
        for (int i = 0; i < n - repeat * b; i++) {
            path.push_back('a' + i); 
        }  
        
        cout << path << endl; 
    }
    
    return 0;
}


/*

1335B构建只有b种的字符串

构建一个长度为 n 的小写字符串，然后每一个长度为 a 的子串中都拥有 b 个不同的字母 

每一个长度为 a 的子串中都只有 b 种不同的字符 

那么可以把每 b 个字符看作一组，一共就存在 n/b 组 


因为 a 一定比 b 大 

所以只要确保每个长度为 b 的区间中只存在这么多的不同的字符
最终对于 a 以及大于等于 b 的所有的长度的子串来说，他们的 unordered_set<>.size() 都和每个区间 b 中的字符数量相同

*/