/**
 * name:  闰年判断
 * link: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P5711#author=0
 * time: 2024/5/17 12:07:35 https://github.com/funcdfs
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

    int64_t n = 0;
    cin >> n;

    auto check = [&]() -> bool {
        if (n % 4) {
            return false;
        } else if (n % 100 == 0) {
            if (n % 400 == 0) {
                return true;
            } else {
                return false;
            }
        }
        return true;
    };

    if (check()) {
        cout << format("{0}\n", 1);
    } else {
        cout << format("{0}\n", 0);
    }

    return 0;
}
/*

*/