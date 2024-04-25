/**
 * author: https://github.com/funcdfs
 * created: 2024-04-09 12:23:39
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
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_set s(a.begin(), a.end());

    vector<int> ans(0, 0);
    for (auto& x : s) ans.push_back(x);
    
    sort(ans.begin(), ans.end());

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << " \n"[i == ans.size()];
    }
    
    return 0;
}
/*

*/