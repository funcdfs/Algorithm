/**
 * problem: https://codeforces.com/contest/776/problem/B
 * created: https://github.com/funcdfs 5/15/2024, 11:28:34 AM
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int n = 0;
    cin >> n;

    auto isPrime = [&](auto x) -> bool {
        if (x < 2) {
            return false;  // 判断是否大于 1
        }
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    };

    vector<int> a(n, 0);
    iota(a.begin(), a.end(), 2);

    vector<int> ans(n, 0);
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            ans[i] = 1;
        } else {
            ans[i] = 2;
            ok = true;
        }
    }
    if (ok == true) {
        cout << format("2\n");
    } else {
        cout << format("1\n");
    }
    for (int i = 0; i < n; i++) {
        cout << format("{0} ", ans[i]);
    }

    return 0;
}
/*

*/