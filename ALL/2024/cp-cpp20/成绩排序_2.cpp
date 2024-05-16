/**
 * author: https://github.com/funcdfs
 * created: 2024-04-01 21:03:41
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
    vector<pair<int, int>> stus(n);
    for (int i = 0; i < n; i++) {
        cin >> stus[i].first >> stus[i].second;
    }

    sort(stus.begin(), stus.end(), [](auto& a, auto& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    });

    for (auto& x : stus) {
        cout << x.first << ' ' << x.second << endl;
    }
    
    return 0;
}
/*

*/