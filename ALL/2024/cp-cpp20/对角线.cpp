/**
 * name:  对角线
 * link: https://vjudge.net/problem/%E6%B4%9B%E8%B0%B7-P2181
 * time: 2024/5/17 11:40:23 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

#define int64_t unsigned long long

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    if (n <= 3) {
        cout << format("{0}\n", 0);
    } else {
        // 每两个顶点连一条对角线 
        // 每两个对角线有一个顶点
        // 一个交点对应四个顶点
        auto C = [](int64_t a, int64_t b) -> int64_t {
            int64_t res = 1;
            for (int64_t i = a, j = 1; j <= b; i--, j++) res = res * i / j;
            return res;
        };
        cout << format("{0}\n", C(n, 4));
    }

    return 0;
}
/*

*/
