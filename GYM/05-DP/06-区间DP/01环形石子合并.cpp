// URL: https://www.acwing.com/problem/content/1070/
// NAME: 环形石子合并, AcWing
// LIMIT: 64 MB, 1000 ms
// DATE: 2022-08-18 14:45:39

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*-----------------------*/

const int INF = 0x3f3f3f3f; 
const int N = 410; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = 0; 
    cin >> n; 
    vector<int> w(2 * n + 2, 0); 
    for (int i = 1; i <= n; i++) {
        cin >> w[i]; 
        w[i + n] = w[i]; 
    }
    vector<int> s(w.size(), 0); 
    for (int i = 1; i <= n * 2; i++) {
        s[i] = s[i - 1] + w[i]; 
    }
    
    vector<vector<int>> f(n * 2 + 1, vector<int>(n * 2 + 1, INF)); 
    vector<vector<int>> g(n * 2 + 1, vector<int>(n * 2 + 1, -INF));
    
    for (int len = 1; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n * 2; l++) {
            int r = l + len - 1;  
            if (l == r) {
                f[l][r] = 0; 
                g[l][r] = 0; 
            } else {
                int x = s[r] - s[l - 1]; 
                for (int k = l; k < r; k++) { 
                // 根据左边的最后一堆的位置来划分不同的切割点，左边最小可以为 1 
                // 所以从 l 开始，右边最小也为 1 所以到 r - 1 的时候就不能再往后了 
                    f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + x); 
                    g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + x); 
                }
            }
        }
    } 
    
    int minVal = INF, maxVal = -INF; 
    for (int i = 1; i <= n; i++) {
        minVal = min(minVal, f[i][i + n - 1]); 
        maxVal = max(maxVal, g[i][i + n - 1]); 
    } 
    
    cout << minVal << "\n" << maxVal << "\n"; 
    
    return 0;
}


/*

输出两两合并的得分的最大值和最小值 

得分是指合并之后的石堆总量的大小 



*/