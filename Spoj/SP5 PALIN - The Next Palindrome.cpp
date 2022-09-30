// LINK: https://www.luogu.com.cn/problem/SP5
// NAME: SP5 PALIN - The Next Palindrome, Luogu
// DATE: 2022.09.20 22:04:42, LIMIT: 1500 MB, 9000 ms

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
        string s = ""; 
        cin >> s; 
        string t = s; 
        
        int cnt9 = count_if(s.begin(), s.end(), [](char c) {
            return c == '9'; 
        }); 
        
        if (cnt9 == s.size()) {
            cout << 1; 
            cout << string(cnt9 - 1, '0'); 
            cout << 1 << '\n'; 
            continue; 
        }
        
        if (s.size() % 2) {
            char mid = s[s.size() / 2]; 
            string pre = s.substr(0, s.size() / 2); 
            string suf = pre; 
            reverse(suf.begin(), suf.end()); 
            pre += mid; 
            pre += suf; 
            dbg(pre);
            if (pre > t) {
                cout << pre << '\n'; 
                continue; 
            } 
            
            int idx = (s.size() + 1) / 2 - 1; 
            while (s[idx] == '9') {
                idx--; 
            } 
            
            pre = s.substr(0, idx); 
            dbg(pre); 
            dbg("Hi", idx); 
            pre += s[idx] + 1; 
            pre += string((s.size() + 1) / 2- idx - 1, '0'); 
            dbg(pre);
            suf = pre; 
            suf.pop_back(); 
            reverse(suf.begin(), suf.end()); 
            pre += suf; 
            cout << pre << '\n'; 
        } else {
            string pre = s.substr(0, s.size() / 2); 
            string suf = pre; 
            reverse(suf.begin(), suf.end()); 
            dbg("even0: ", pre); 
            pre += suf; 
            if (pre > t) {
                cout << pre << '\n'; 
                continue; 
            }
            
            int idx = s.size() / 2 - 1; 
            while (s[idx] == '9') {
                idx--;  
            } 
            pre = s.substr(0, idx); 
            dbg("even1: ", pre); 
            pre += s[idx] + 1; 
            pre += string(s.size() / 2 - idx - 1, '0'); 
            suf = pre; 
            reverse(suf.begin(), suf.end()); 
            pre += suf; 
            
            cout << pre << '\n'; 
        }
    }
    
    return 0;
}


/*

下一个回文数

如果所有数位都是 9 
那么就是这个数字 +2 

以这个数字的前一半为基础做出一个回文数，和原数字比较大小，如果比原本的数字大， 直接输出 
否则从中间开始往前找第一位不是 9 的，将此位和他的对称位置加 1，他们中间全部置为 0 
这样可以保证他比原本的数字大，并且是最小的回文数

*/