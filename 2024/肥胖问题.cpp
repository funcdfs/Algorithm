/**
 * name:  肥胖问题
 * link: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P5714
 * time: 2024/5/17 12:16:33 https://github.com/funcdfs
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

    double m, h;
    cin >> m >> h;

    double bmi = m / (h * h);

    if (bmi < 18.5) {
        cout << format("Underweight\n");
    } else if (bmi >= 18.5 and bmi < 24) {
        cout << format("Normal\n");
    } else if (bmi >= 24) {
        cout << bmi;
        cout << format("\n");
        cout << format("Overweight\n");
    }

    return 0;
}
/*

*/