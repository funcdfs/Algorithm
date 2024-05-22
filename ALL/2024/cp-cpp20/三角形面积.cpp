/**
 * name:  三角形面积
 * link: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P5708
 * time: 2024/5/17 11:28:24 https://github.com/funcdfs
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

    double a, b, c;
    cin >> a >> b >> c;
    vector<double> x{a, b, c};
    ranges::sort(x);
    if (x[0] + x[1] <= x[2]) {
        cout << format("0.0\n");
        return 0;
    }

    double p = (a + b + c) / 2;
    double ans = (p - a) * (p - b) * (p - c) * p;

    cout << format("{:.1f}\n", sqrt(ans));

    return 0;
}
/*

*/