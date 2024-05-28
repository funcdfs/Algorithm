/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1935/problem/A
 * created: 5/14/2024, 11:17:27 AM
 **/

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL /* For Local Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

auto solve() -> void {
    int n = 0;
    cin >> n;
    string s;
    cin >> s;
    assert(n % 2 == 0);
    string originalS = s;
    for (int i = 0; i < n; i++) {
        string lastLoopS = s;
        string reverseS = s;
        reverse(reverseS.begin(), reverseS.end());
        string a = lastLoopS + reverseS;
        string b = reverseS;
        if (b < a)
            s = b;
        else
            s = a;
        if (s == lastLoopS) break;
    }
    if (s > originalS) s = originalS;
    cout << format("{0}\n", s);
    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}
/*

*/