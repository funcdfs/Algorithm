// LINK: https://codeforces.com/contest/1368/problem/B
// NAME: B. Codeforces Subsequences, Codeforces - Codeforces Global Round 8
// DATE: 2022-09-10 15:19:06, LIMIT: 512 MB, 2000 ms

#include <bits/stdc++.h>

using namespace std;
/*----------------------------------*/
#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif
/*----------------------------------*/

string s = "codeforces"; 

int main() {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = s.size(); 
    
    int64_t k = 0; 
    cin >> k; 
    
    vector<int> v(10, 1); 
    for (int i = 0; ; i = (i + 1) % n) {
        int64_t p = 1; 
        for (int x : v) p *= x; 
        if (p >= k) {
            break; 
        }
        v[i] += 1; 
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < v[i]; j++) {
            cout << s[i]; 
        }
    }
    cout << '\n'; 

    return 0;
}


/*

1368B构建一个含有k次cf的最短的字符串

idea: https://codeforces.com/contest/1368/submission/84174471

![](https://raw.githubusercontent.com/psychonaut1f/a/main/img/20220910160658.png)

*/