// LINK: https://codeforces.com/contest/1352/problem/F
// NAME: F. Binary String Reconstruction, Codeforces - Codeforces Round #640 (Div. 4)
// DATE: 2022.09.15 22:43:43, LIMIT: 256 MB, 1000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/



int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        int n0 = 0, n1 = 0, n2 = 0; 
        cin >> n0 >> n1 >> n2; 
        
        if (n1 == 0) {
            if (n0 == 0) {
                for (int i = 0; i < n2 + 1; i++) {
                    cout << 1;
                }
            } else {
                for (int i = 0; i < n0 + 1; i++) {
                    cout << 0; 
                }
            }
            cout << '\n'; 
            continue; 
        }
        
        string s = ""; 
        s.reserve(n0 + n2 + 2); 
        s += string(n0 + 1, '0'); 
        s += string(n2 + 1, '1'); 
        n1--; 
        cout << s; 
        for (int i = 0; i < n1; i++) {
            if (i & 1) {
                cout << 1; 
            } else {
                cout << 0; 
            }
        }
        cout << '\n'; 
    }
    
    return 0;
}


/*

1352F构造长度为2的01子序列满足具体和的数量

需要构造一个 01 组成的字符串

对于这个字符串中的每一个长度为 2 的连续的子串, 和定义为这两个数字的加和

总共存在，n0 个和为 0，有 n1 个和为 1， 有 n2 个和为 2 

保证输入存在解, 输出任意一组解


此时已经存在一组的和是 1 

对于剩下的 n1 -1 个和为 1 的子序列 
只需要按照 0, 1, 0, 1, 0 的顺序拼接在最后面即可, 
添加一个 0，n1--, 再添加一个 1, n1 再次-- 。。。

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220915230619.png)

*/