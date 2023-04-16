/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-14 19:21:10
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
        vector<int> a(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int preLen = 1;
        while (preLen < n and a[preLen] <= a[preLen + 1]) preLen += 1;
        int sufLen = 1;
        while (sufLen < n and a[n - sufLen] >= a[n - sufLen + 1]) sufLen += 1;
        if (preLen + sufLen >= n) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
/*

*/