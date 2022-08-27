// LINK: https://codeforces.com/contest/1553/problem/D
// NAME: D. Backspace, Codeforces - Harbour.Space Scholarship Contest 2021-2022 (open for everyone, rated, Div. 1 + Div. 2)
// DATE: 2022-08-24 16:26:42, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*----------------------------------*/

bool canTrans(string& a, string& b) {
    int idxA = 0; 
    if ((a.size() % 2) != (b.size() % 2)) {
        idxA++; 
    } 
    
    int cnt = 0; 
    for (int i = 0; i < b.size();) {
        if (idxA >= a.size()) break; 
        if (a[idxA] == b[i]) {
            idxA++; 
            i++; 
            cnt++; 
        } else {
            idxA += 2; 
        } 
    } 
    return cnt == b.size(); 
}

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int q = 0; 
    cin >> q; 
    
    while (q--) {
        string s = ""; 
        cin >> s; 
        string t = ""; 
        cin >> t; 
        
        if (canTrans(s, t)) {
            cout << "YES" << "\n"; 
        } else {
            cout << "NO" << "\n"; 
        }
    }
    
    return 0;
}


/*

1553D使用backspace能否转换为指定的字符串

1：将首个字符变为删除键
    仅仅起到了删除首个字符的作用
2：单独的一个删除键
    连续删除了两个字符
3：连续的 K 个删除键
    共连续的 2k 个字符被删除

所以，除去首位删除一个字符之外，此后的所有操作都删除了连续的两个字符

因为最终 s 需要删除到和 t 一摸一样
所以当 奇偶性不同的时候，就必须要删除首位

接着使用双指针
从前往后再 s 中依次匹配 t 串的各个字符，如果在 s 串中这一位没有匹配到，则说明这一位和下一位都必须删除
检查是否匹配完成即可 

*/