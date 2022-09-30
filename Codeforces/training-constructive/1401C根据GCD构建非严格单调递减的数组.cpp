// LINK: https://codeforces.com/contest/1401/problem/C
// NAME: C. Mere Array, Codeforces - Codeforces Round #665 (Div. 2)
// DATE: 2022-09-09 17:49:57, LIMIT: 256 MB, 2000 ms

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
        vector<int> a(n, 0); 
        for (int i = 0; i < n; i++) cin >> a[i]; 
        
        function<bool()> trans = [&]() -> bool {
            int x = *min_element(a.begin(), a.end()); 
            auto b = a; 
            sort(b.begin(), b.end()); 
            
            for (auto& i : a) {
                if (i % x == 0) {
                    i = -1; 
                }
            } 
            
            for (auto& i : b) {
                if (i % x == 0) {
                    i = -1; 
                }
            } 
            
            return a == b; 
        };
        
        if (trans()) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n"; 
        }
    }
    
    return 0;
}


/*

1401C根据GCD构建非严格单调递减的数组

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220909181513.png)

*/