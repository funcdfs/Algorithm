// URL: https://codeforces.com/contest/1709/problem/B
// NAME: B. Also Try Minecraft, Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// LIMIT: 256 MB, 2000 ms
// DATE: 2022-08-16 21:46:28

#include <bits/stdc++.h>

using namespace std;

#ifdef github_fengwei2002
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
/*-----------------------*/

typedef long long LL; 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, tt; 
    cin >> n >> tt; 
    vector<int> a(n); 
    for (int i = 0; i < n; i++) cin >> a[i]; 
    
    vector<int> diff(n - 1); 
    vector<LL> sum(n); 
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] < a[i]) {
            diff[i] = a[i] - a[i + 1]; 
        } else {
            diff[i] = 0; 
        }
    } 
    for (int i = 1; i <= n - 1; i++) {
        sum[i] = sum[i - 1] + diff[i - 1]; 
    }
    debug(diff); 
    debug(sum); 
    
    vector<int> rDiff(n - 1); 
    vector<LL> rSum(n); 
    for (int i = n - 2; i >= 0; i--) {
        if (a[i + 1] > a[i]) {
            rDiff[i] = a[i + 1] - a[i]; 
        } else {
            rDiff[i] = 0; 
        }
    }  
    rSum[n - 1] = rDiff.back(); 
    for (int i = n - 2; i >= 0; i--) {
        rSum[i] = rSum[i + 1] + rDiff[i]; 
    }
    debug(rDiff); 
    debug(rSum); 
    
    while (tt--) {
        int l, r; 
        cin >> l >> r; 
        l--; 
        r--; 
        
        if (l < r) {
            cout << sum[r] - sum[l] << '\n'; 
        } else {
            cout << -(rSum[l] - rSum[r]) << '\n';
        }
    }

    return 0;
}


/*

1709B耗费的最小力量

双向前缀和

最终写法:
https://codeforces.com/contest/1709/submission/168544768

*/