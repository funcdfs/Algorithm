// LINK: https://codeforces.com/contest/443/problem/A
// NAME: A. Anton and Letters, Codeforces - Codeforces Round #253 (Div. 2)
// DATE: 2022-08-31 12:08:15, LIMIT: 256 MB, 2000 ms

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
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    unordered_set<char> S; 
    string s = ""; 
    getline(cin, s, '\n'); 
    
    for (auto& c : s) {
        if (isalpha(c)) {
            S.insert(c); 
        }
    } 
    
    cout << S.size() << '\n'; 
    
    return 0;
}


/*

443A不同字符的数量

*/