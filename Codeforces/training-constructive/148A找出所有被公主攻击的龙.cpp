// LINK: https://codeforces.com/contest/148/problem/A
// NAME: A. Insomnia cure, Codeforces - Codeforces Round #105 (Div. 2)
// DATE: 2022-08-31 11:54:24, LIMIT: 256 MB, 2000 ms

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

    vector<int> a(5, 0);
    for (auto& x : a) cin >> x;
    // K, L, M, N --> total d 
    
    vector<bool> st(a.rbegin()[0] + 1, false); 
    
    for (int i = 0; i < a.size() - 1; i++) {
        int x = a[i]; 
        for (int j = x; j <= a.rbegin()[0]; j += x) {
            st[j] = true; 
        }
    }    
    /*
        for (int i = 1; i <= d; ++i)
            if (!(i % k && i % m && i % n && i % l))
                s++;
    */
    cout << count(st.begin(), st.end(), true) << '\n'; 
    
    return 0;
}

/*

148A找出所有被公主攻击的龙

从前往后模拟一遍，同时使用 count 可以直接返回一个 bool 中的元素的数量

*/