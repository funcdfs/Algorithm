/**
 * author:  https://github.com/funcdfs
 * problem: https://www.luogu.com.cn/problem/CF1914B
 * created: 5/13/2024, 8:50:35 PM
 **/

#include <bits/stdc++.h>
using namespace std;
auto solve() -> void {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> a(n, 0);
    iota(a.begin(), a.end(), 1);
    if (k == 0) {
        for (int x : a | std::views::reverse) {
            cout << std::format("{0} ", x);
        }
        cout << std::format("\n");
        return;
    } else {
        int cnt = n - 1;
        int idx = 0;
        while (idx < n / 2) {
            if (cnt <= k) break;
            swap(a.begin()[idx], a.rbegin()[idx]);
            cnt -= 2;
            idx += 1;
        }
        if (cnt < k) {
            if (a.rbegin()[1] == n - 1) {
                swap(a.begin()[0], a.rbegin()[0]);
                // restore to default
            }
            swap(a.rbegin()[0], a.rbegin()[1]);
            // make it to right cnt;
        }
        for (int x : a) {
            cout << std::format("{0} ", x);
        }
        cout << std::format("\n");
    }
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