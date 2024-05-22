/**
 * name:  洛谷团队系统
 * link: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P5713
 * time: 2024/5/17 12:14:00 https://github.com/funcdfs
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

    auto check = [&]() -> bool {
        int64_t a = n * 5;
        int64_t b = n * 3 + 11;
        if (a < b) {
            return true;
        }
        return false;
    };
    if (check()) {
        cout << format("Local\n");
    } else {
        cout << format("Luogu\n");
    }

    return 0;
}
/*

*/