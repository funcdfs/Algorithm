// LINK: https://codeforces.com/contest/1454/problem/D
// NAME: D. Number into Sequence, Codeforces - Codeforces Round #686 (Div. 3)
// DATE: 2022-09-09 22:49:01, LIMIT: 256 MB, 3000 ms

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
        int64_t n = 0; 
        cin >> n; 
        vector<pair<int64_t, int>> p(0); 
        int64_t t = n; 
        for (int64_t i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int64_t x = i; 
                int y = 0; 
                while (n % i == 0) {
                    n /= i; 
                    y++; 
                }
                p.push_back({x, y}); 
            }
        }
        
        if (n > 1) {
            p.push_back({n, 1}); 
        }
        
        dbg(p); 
        // 因子出现的频次数组 
        
        int maxFreq = 0; 
        int maxFreqIndex = 0; 
        for (int i = 0; i < (int)p.size(); i++) {
            if (p[i].second > maxFreq) {
                maxFreq = p[i].second; 
                maxFreqIndex = i; 
            }
        }
        
        cout << maxFreq << '\n'; 
        for (int i = 0; i < maxFreq - 1; i++) {
            cout << p[maxFreqIndex].first << ' '; 
            t /= p[maxFreqIndex].first; 
        }
        cout << t << '\n'; 
    }
    
    return 0;
}


/*

1454D输出按照因子拆分之后的最大长度


乘积是 n 同时需要满足，后面一个数字是前面一个数字的倍数

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220909233736.png)

*/