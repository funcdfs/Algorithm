// LINK: https://codeforces.com/contest/401/problem/C
// NAME: C. Team, Codeforces - Codeforces Round #235 (Div. 2)
// DATE: 2022-09-10 16:09:29, LIMIT: 256 MB, 1000 ms

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

    int n = 0, m = 0;
    cin >> n >> m;
    // n is zero count, m is one count
    
    function<bool(int, int)> isGood = [&](int n, int m) {
        int minSpaceCnt = (m % 2 ? m / 2 + 1 : m / 2) - 1; 
        int maxSpaceCnt = m + 1; 
        if (n >= minSpaceCnt && n <= maxSpaceCnt) {
            return true; 
        } 
        return false; 
    }; 
    
    if (isGood(n, m) == false) {
        cout << -1 << '\n'; 
        return 0; 
    } 
    
    if (m == n - 1) {
        for (int i = 0; i < m; i++) cout << "01"; 
        cout << "0\n"; 
    } else {
        while (n > 0) {
            if (m > n) {
                cout << "1"; 
                m--; 
            }
            cout << "10"; 
            m--; 
            n--; 
        }
        
        for ( ; m > 0; m--) {
            cout << "1"; 
        }
        cout << '\n'; 
    }

    return 0;
}

/*

401C给定01个数构建最多连续两个一和一个零



*/