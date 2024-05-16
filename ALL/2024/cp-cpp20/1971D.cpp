/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1971/problem/D
 * created: 5/10/2024, 11:11:54 PM
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
        string s;
        cin >> s;
        int n = (int)s.size();

        int ans = 0;
        bool flag = false;
        for (int i = 0; i + 1 < n; i++) {
            if (s[i] != s[i + 1]) {
                ans += 1;
                if (s[i] == '0' and s[i + 1] == '1') {
                    flag = true;
                }
            }
        }
        ans += 1;
        if (flag == true) cout << ans - 1 << endl;
        else cout <<ans << endl;
    }

    return 0;
}
/*

*/