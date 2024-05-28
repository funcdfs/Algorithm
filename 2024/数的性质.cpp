/**
 * name:  数的性质
 * link: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P5710
 * time: 2024/5/17 11:59:49 https://github.com/funcdfs
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

    bool ok1 = false, ok2 = false;
    if (n % 2 == 0) ok1 = true;
    if (n > 4 and n <= 12) ok2 = true;
    dbg(ok1, ok2);

    if (ok1 and ok2)
        cout << format("{0} ", 1);
    else
        cout << format("{0} ", 0);

    if (ok1 or ok2)
        cout << format("{0} ", 1);
    else
        cout << format("{0} ", 0);

    if (ok1 ^ ok2)
        cout << format("{0} ", 1);
    else
        cout << format("{0} ", 0);

    if (!ok2 and !ok1) {
        cout << format("{0} ", 1);
    } else {
        cout << format("{0} ", 0);
    }
    return 0;
}
/*

*/