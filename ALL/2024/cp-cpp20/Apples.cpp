/**
 * name:  Apples
 * link: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P5712
 * time: 2024/5/17 12:12:20 https://github.com/funcdfs
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
    if (n > 1) {
        cout << format("Today, I ate {} apples.\n", n);
    } else {
        cout << format("Today, I ate {} apple.\n", n);
    }

    return 0;
}
/*

*/