/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-17 11:49:54
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
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        string s(200, 'a');
        cout << s << '\n';

        for (int i = 0; i < n; i++) {
            if (s[a[i]] == 'a') {
                s[a[i]] = 'b';
            } else if (s[a[i]] == 'b') {
                s[a[i]] = 'a';
            }
            cout << s << '\n';
        }
    }
    
    return 0;
}
/*

*/