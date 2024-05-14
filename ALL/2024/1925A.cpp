/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1925/problem/A
 * created: 5/13/2024, 9:06:19 PM
 **/

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL /* For Local Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

auto solve() -> void {
    int n = 0, k = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << std::format("{0}", char(j + 'a'));
        }
    }
    cout << std::format("\n");
    // vector<string> ans(0);
    // auto dfs = [&](auto&& self, string s) -> void {
    //     if ((int)s.size() == n) {
    //         ans.push_back(s);
    //         return;
    //     }
    //     for (int i = 0; i < k; i++) {
    //         char c = (char)(i + 'a');
    //         s += c;
    //         self(self, s);
    //         s.pop_back();
    //     }
    // };
    // dfs(dfs, "");
    // for (auto& s : ans) {
    //     cout << std::format("{0}", s);
    // }
    // cout << std::format("\n");
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