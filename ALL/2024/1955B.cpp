/**
 * problem: https://codeforces.com/contest/1955/problem/B
 * created: https://github.com/funcdfs 5/14/2024, 11:21:18 PM
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto solve() -> void {
    int n = 0, c = 0, d = 0;
    cin >> n >> c >> d;
    vector<int> b(n * n, 0);
    for (int i = 0; i < n * n; i++) cin >> b[i];
    unordered_map<int, int> hs;
    for (auto& x : b) hs[x] += 1;
    ranges::sort(b);
    dbg(b);
    auto check = [&]() -> bool {
        int a_11 = *min_element(b.begin(), b.end());
        dbg(a_11);
        vector<int> a(n, 0);
        a[0] = a_11;
        for (int i = 1; i < n; i++) {
            a[i] = a[i - 1] + d;
        }
        dbg(a);
        unordered_map<int, int> freq;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (auto& x : a) {
                freq[x] += 1;
                if (hs.contains(x) == false) {
                    return false;
                }
                x += c;
            }
            cnt += 1;
            if (cnt == n) break;
            dbg(cnt, a);
        }
        for (auto& [k, v] : freq) {
            if (hs.contains(k) == false) return false;
            if (hs[k] != v) return false;
        }
        return true;
    };
    if (check() == true) {
        cout << format("YES\n");
    } else {
        cout << format("NO\n");
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
/*

*/