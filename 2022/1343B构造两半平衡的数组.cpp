// LINK: https://codeforces.com/contest/1343/problem/B
// NAME: B. Balanced Array, Codeforces - Codeforces Round #636 (Div. 3)
// DATE: 2022-09-01 22:47:07, LIMIT: 256 MB, 1000 ms

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
        
        vector<int> a(0, 0); 
        
        if (n % 4 == 0) {
            int half = n / 2; 
            int even = 2; 
            int odd = 1; 
            
            for (int i = 0; i < half; i++) {
                a.push_back(even); 
                even += 2; 
            } 
            
            int diff = 1;  
            for (int i = 0; i < half - 1; i++) {
                a.push_back(odd); 
                diff++; 
                odd += 2; 
            }
            
            a.push_back(odd + diff); 
            cout << "YES" << '\n'; 
            for (int i = 0; i < a.size(); i++) {
                cout << a[i] << " \n"[i == a.size() - 1]; 
            }
        } else {
            cout << "NO" << '\n'; 
        }
    }
    
    return 0;
}


/*

1343B构造两半平衡的数组



*/