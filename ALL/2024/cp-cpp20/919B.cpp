/**
 * name: B. Perfect Number
 * link: https://codeforces.com/contest/919/problem/B
 * time: 2024/5/17 13:30:58 https://github.com/funcdfs
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

    int k = 0;
    cin >> k;

    // 19
    // 28
    // 37
    // 46
    // 55
    // 64
    // 73
    // 82
    // 91
    // 109
    // 118
    // ...

    vector<int64_t> ans(10001, 0);
    int idx = 0;

    auto calc = [&](int64_t x) -> int {
        int sum = 0;
        while (x) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    };

    int64_t num = 0;
    while (idx <= 10000) {
        if (calc(num) == 10) {
            ans[idx] = num;
            idx += 1;
        }
        num += 1;
    }

    cout << format("{0}\n", ans[k - 1]);

    return 0;
}
/*
当且仅当一个正整数的数位之和恰好是 $10$
时，我们才认为它是完全正整数。给定一个正整数 $k$ ，你的任务是找出 $k$ th
最小的完美正整数。
*/