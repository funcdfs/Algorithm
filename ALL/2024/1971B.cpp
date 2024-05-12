/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1971/problem/B
 * created: 5/10/2024, 10:46:56 PM
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
        dbg(s);
        unordered_map<char, int> hs;
        for (int i = 0; i < (int)s.size(); i++) {
            hs[s[i]] += 1;
        }
        if ((int)hs.size() == 1) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (int i = 1; i < (int)s.size(); i++) {
                if (s[i] != s[0]) {
                    swap(s[i], s[0]);
                }
            }
            cout << s << endl;
        }
    }

    return 0;
}
/*

*/