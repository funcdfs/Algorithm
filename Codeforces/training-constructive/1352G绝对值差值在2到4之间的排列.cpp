// LINK: https://codeforces.com/contest/1352/problem/G
// NAME: G. Special Permutation, Codeforces - Codeforces Round #640 (Div. 4)
// DATE: 2022-09-10 17:22:01, LIMIT: 256 MB, 2000 ms

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
        int n = 0; 
        cin >> n; 
        
        if (n <= 3) {
            cout << -1 << '\n'; 
        } else {
            deque ans{3, 1, 4, 2}; 
            for (int i = 5; i <= n; i += 2) {
                ans.push_front(i); 
            }
            for (int i = 6; i <= n; i += 2) {
                ans.push_back(i); 
            } 
            for (int i = 0; i < (int)ans.size(); i++) {
                cout << ans[i] << " \n"[i == (int)ans.size() - 1]; 
            }
        }
    } 
    
    return 0;
}


/*

1352G绝对值差值在2到4之间的排列

idea from jiangly:
https://codeforces.com/contest/1352/submission/79517347

*/