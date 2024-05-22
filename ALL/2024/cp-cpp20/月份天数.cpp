/**
 * name:  月份天数
 * link: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P5716
 * time: 2024/5/17 12:23:40 https://github.com/funcdfs
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

    int y, m;
    cin >> y >> m;

    array<int, 13> day{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n = y;
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
        day[2] = 29;
    }
    cout << format("{0} ", day[m]);

    return 0;
}
/*

*/