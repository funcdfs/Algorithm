/**
 * author: https://github.com/funcdfs
 * created: 2024-04-01 20:54:50
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

    int n = 0;
    cin >> n;
    int x = 0;
    cin >> x;
    vector<pair<string, int>> stus(n);
    for (int i = 0; i < n; i++) {
        cin >> stus[i].first >> stus[i].second;
    }
    if (x == 0) {
        stable_sort(stus.begin(), stus.end(), [](auto& a, auto& b) {
            return a.second > b.second;
        });
    } else {
        stable_sort(stus.begin(), stus.end(), [](auto& a, auto& b) {
            return a.second < b.second;
        });
    }

    for (auto& x : stus) {
        cout << x.first << ' ' << x.second << endl;
    }

    return 0;
}
/*

*/