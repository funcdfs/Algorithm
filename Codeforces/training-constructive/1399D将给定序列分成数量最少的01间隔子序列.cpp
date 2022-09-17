// LINK: https://codeforces.com/contest/1399/problem/D
// NAME: D. Binary String To Subsequences, Codeforces - Codeforces Round #661 (Div. 3)
// DATE: 2022-09-10 23:08:37, LIMIT: 256 MB, 2000 ms

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
        int n = 0; 
        cin >> n; 
        string s = ""; 
        cin >> s; 
        
        int cnt = 0; 
        vector<int> seq[2]; 
        vector<int> ans; 
        
        ans.reserve(n); 

        for (auto& c : s) {
            int x = c - '0'; 
            if (seq[!x].empty()) { // 没有前缀相反的
                seq[x].push_back(++cnt); // 新开一个序列
                ans.push_back(cnt); // ans 中的这一位是新开序列的编号 
            } else {
                ans.push_back(seq[!x].back()); // 否则有前缀相反的，ans 中的这一位编号是前缀序列的编号
                seq[x].push_back(seq[!x].back()); 
                seq[!x].pop_back(); 
            }
        }
        
        cout << cnt << "\n"; 
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1]; 
        }
    }
    
    return 0;
}


/*

子序列不包含相邻的 0 或者相邻的 1  

1399D将给定序列分成数量最少的01间隔子序列


input: 
1
5
00100

output: 
3
1 2 2 2 3

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220911100707.png)

*/