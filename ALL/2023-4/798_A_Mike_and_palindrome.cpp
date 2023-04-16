/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-16 15:59:49
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

    string s = "";
    cin >> s;
    // change one char to make reverse(str) == str;

    string t(s.rbegin(), s.rend());

    int diffCnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != t[i]) {
            diffCnt += 1;
        }
    }

    if ((int)s.size() % 2) {
        if (diffCnt == 0 or diffCnt == 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        if (diffCnt == 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
/*

*/