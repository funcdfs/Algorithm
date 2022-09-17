// LINK: https://codeforces.com/contest/1332/problem/B
// NAME: CF1332B Composite Coloring
// DATE: 2022.09.13 15:48:50, LIMIT: 500 MB, 2000 ms

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
        vector<int> a(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        unordered_map<int, int> hs; 
        vector<int> colorId(n, 0); 
        for (int i = 0; i < n; i++) {
            int x = 2; 
            while (a[i] % x != 0) {
                x++; 
            }
            if (hs.contains(x)) {
                colorId[i] = hs[x]; 
            } else {
                hs[x] = hs.size() + 1; 
                colorId[i] = hs[x]; 
            }
        }
        // 将 a 中的数字换成每一个数字的最小的不是 1 的因子 
        
        cout << hs.size() << '\n'; 
        for (int i = 0; i < n; i++) {
            cout << colorId[i] << " \n"[i == n - 1]; 
        }
    }

    return 0;
}

/*

1332B用m种颜色染色数组


给定 n 个数字（每一个数字都是合数），要求将他分为不超过 11 组，保证每一个组里面两两不互质 


考虑给每一个数字的因数染色， 对于每一个数字都分解因数，如果存在已经被染色的因数 
就把这个数字也染成这个颜色，否则新开一个颜色

*/