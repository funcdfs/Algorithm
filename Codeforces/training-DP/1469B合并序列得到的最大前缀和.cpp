// URL: https://codeforces.com/contest/1469/problem/B
// NAME: B. Red and Blue, Codeforces - Educational Codeforces Round 101 (Rated for Div. 2)
// LIMIT: 512 MB, 2000 ms, DATE: 2022-08-21 20:16:17


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
    cin.tie(0)->sync_with_stdio(false);
    
    int tt = 0; 
    cin >> tt; 
    while (tt--) {
        int n = 0; 
        cin >> n; 
        vector<int> r(n, 0); 
        for (int i = 0; i < n; i++) cin >> r[i]; 
        int m = 0; 
        cin >> m; 
        vector<int> b(m, 0); 
        for (int i = 0; i < m; i++) cin >> b[i]; 
        
        // console.log(max(f(a)))
        
        vector<int> sRed(n + 1, 0); 
        vector<int> sBlue(m + 1, 0); 
        int maxSumRed = 0; 
        int maxSumBlue = 0; 
        for (int i = 1; i <= n; i++) {
            sRed[i] = sRed[i - 1] + r[i - 1]; 
            maxSumRed = max(maxSumRed, sRed[i]); 
        } 
        for (int i = 1; i <= m; i++) {
            sBlue[i] = sBlue[i - 1] + b[i - 1]; 
            maxSumBlue = max(maxSumBlue, sBlue[i]); 
        }
        debug(r, b); 
        debug(sRed, sBlue); 
        debug(maxSumRed, maxSumBlue); 
        cerr << "\n"; 
        cout << maxSumRed + maxSumBlue << "\n"; 
    }
    
    return 0;
}


/*

1469B合并序列得到的最大前缀和

把两个序列按照原来的顺序插入到其中的一个序列中，求这个序列可以得到的最大的从 1 开始的前缀和  

所以就按照他的要求

把第二个序列中的最大部分插入到第一个序列的而最大部分就是最终的答案 

4
6 -5 7 -3
3
2 3 -4

8 + 5; 

*/