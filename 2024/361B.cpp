/**
 * problem: https://codeforces.com/contest/361/problem/B
 * created: https://github.com/funcdfs 2024/5/16 14:03:05
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

    int n = 0, k = 0;
    cin >> n >> k;

    if (n == k) {
        cout << format("-1\n");
        return 0;
    }
    for (int i = 1; i < n - k; i++) {
        cout << format("{0} ", i + 1);
    }  // equal 1
    cout << format("{0} ", 1);  // equal 1
    for (int i = n - k + 1; i <= n; i++) {
        cout << format("{0} ", i);
    }  // greater than 1
    return 0;
}
/*

cnt( gcd(i, a[i]) > 1 ) == k

gcd(i, i) = i

gcd(1, i) = 1

gcd(i, i + 1) = 1

*/