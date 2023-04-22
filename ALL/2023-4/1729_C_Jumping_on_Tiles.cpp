/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-18 14:23:54
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
        string s = "";
        cin >> s;
        int n = (int)s.size();
        vector<vector<int>> p(26);
        for (int i = 0; i < n; i++) {
            p[s[i] - 'a'].push_back(i);
        }
        vector<int> ans;
        if (s[0] <= s.back()) {
            for (char c = s[0]; c <= s.back(); c++) {
                for (int pi : p[c - 'a']) {
                    ans.push_back(pi);
                    // move to pi;
                }
            }
        } else {
            for (char c = s[0]; c >= s.back(); c--) {
                for (int pi : p[c - 'a']) {
                    ans.push_back(pi);
                }
            }
        }
        cout << abs(s[0] - s.back()) << ' ' << ans.size() << '\n';
        for (int p : ans) {
            cout << p + 1 << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
/*

*/