/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-17 10:51:37
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0;
        cin >> n;
        string s = string(n, ' ');
        cin >> s;
        // exactly n / 2 zeros and n / 2 ones (n is even)
        // minimum number to reserve substring to make string s alternating
        int same = 0;
        for (int i = 1; i < n; i++) {
            same += s[i - 1] == s[i];
        }
        // when reverse an substring, the edge two group will change
        // eg: s[i] == s[i - 1] will be s[i] != s[i - 1]
        // so accumulate the count of the same poisition, then div 2
        cout << (same + 2 - 1) / 2 << '\n';
    } 
    return 0;
}
/*

*/