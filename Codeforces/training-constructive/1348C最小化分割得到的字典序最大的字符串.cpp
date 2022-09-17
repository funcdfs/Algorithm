// LINK: https://codeforces.com/contest/1348/problem/C
// NAME: C. Phoenix and Distribution, Codeforces - Codeforces Round #638 (Div. 2)
// DATE: 2022.09.16 15:09:12, LIMIT: 256 MB, 2000 ms

#include <bits/stdc++.h>
using namespace std;
/*----------------------------------*/
#ifdef github_fengwei2002
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
        int n = 0, k = 0; 
        cin >> n >> k; 
        
        string s = string(n, ' '); 
        cin >> s; 
        
        sort(s.begin(), s.end()); 
        
        if (s[k - 1] != s[0]) {
            cout << s[k - 1] << '\n'; 
        } else if (k == n || s[k] != s[n - 1]) {
            cout << s.substr(k - 1) << '\n'; 
        } else {
            // The element in [k:] types are less than two, equal 1
            // To make the largest lexicographical order the smallest, 
            // the remaining letters must be distributed evenly
            
            string t = string(1, s[0]); // the prefix
            string leftPart = string((n - 1) / k, s.rbegin()[0]); 
            t.append(leftPart);      
            
            cout << t << '\n'; 
        }
    }
    
    return 0;
}


/*

1348C最小化分割得到的字典序最大的字符串


找到合理的分布。并且打印可以得到的最大的字典序字符串
共有 k 个部分

所以应该使用 k 个最小的字符，作为每一个字符串的开头字符

- 如果已经至少出现了 2 种字符，应该把剩下的部分，全部放到某一个最小的字符的后面 
答案就是第 k 大的字符 
- 前 k 大的字符相同，如果剩下的全部相同，就应该平均分配 
    - 如果剩下的不完全相同，则应该全部接到某一个后面就是最优解


*/