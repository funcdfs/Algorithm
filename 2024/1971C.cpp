/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1971/problem/C
 * created: 5/10/2024, 10:43:52 PM	
**/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int TT = 0;
    cin >> TT;
    while (TT--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        // c d in the middle of a and b 
        // or the ab in the middle of c and d

        auto check = [](int a, int b, int c, int d) -> bool {
            if (a > b) swap(a, b);
            if ((c >= a and c <= b) and (d >= b or d <= a)) return true;
            swap(c, d);
            if ((c >= a and c <= b) and (d >= b or d <= a)) return true;
            return false;
        };

        if (check(a, b, c, d)) { 
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
/*

*/