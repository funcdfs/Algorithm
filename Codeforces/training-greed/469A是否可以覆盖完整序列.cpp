// LINK: https://codeforces.com/contest/469/problem/A
// NAME: A. I Wanna Be the Guy, Codeforces - Codeforces Round #268 (Div. 2)
// DATE: 2022-08-22 22:58:34, LIMIT: 256 MB, 1000 ms

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
    
    int n = 0; 
    cin >> n; 
    int p = 0, p2 = 0; 
    cin >> p; 
    vector<int> a(p, 0); 
    for (int i = 0; i < p; i++) cin >> a[i]; 
    cin >> p2; 
    vector<int> a2(p2, 0); 
    for (int i = 0; i < p2; i++) cin >> a2[i]; 
    
    set<int> s1, s2; 
    for (int i = 1; i <= n; i++) s1.insert(i); 
    for (int i = 0; i < p; i++) s2.insert(a[i]); 
    for (int i = 0; i < p2; i++) s2.insert(a2[i]); 
    
    if (s1 == s2) {
        cout << "I become the guy." << "\n"; 
    } else {
        cout << "Oh, my keyboard!" << "\n"; 
    }
    
    return 0;
}


/*

469A是否可以覆盖完整序列

*/