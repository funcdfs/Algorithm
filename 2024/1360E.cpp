/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1360/problem/E
 * created: 5/7/2024, 7:58:59 PM
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
        int n = 0;
        cin >> n;
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        auto check = [&]() -> bool {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (a[i][j] == '1') {
                        if (i + 1 != n and a[i + 1][j] != '1' and j + 1 != n and
                            a[i][j + 1] != '1') {
                            return false;
                        }
                    }
                }
            }
            return true;
        };
        if (check())
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
/*

*/