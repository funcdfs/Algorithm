/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1914/problem/B
 * created: 5/13/2024, 7:37:46 PM
 **/

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL /* For Local Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

auto solve() -> void {
    int n = 0, k = 0;
    cin >> n >> k;
    vector<int> a(n, 0);
    // 构建一个长度为 n 的数组，其中有 k 个单调递增的数字对
    iota(a.begin(), a.end(), 1);
    // dbg(n, k, a);
    if (k == 0) {
        for (int i : a | std::views::reverse) {
            cout << std::format("{0} ", i);
        }
        cout << std::format("\n");
        return;
    }
    int idx = 0;
    int cnt = n - 1;
    while (idx < n / 2) {
        if (cnt <= k) break;
        swap(a.begin()[idx], a.rbegin()[idx]);
        cnt -= 2;
        idx += 1;
    }

    if (cnt < k) {
        // 过多了，最多只可能多产生一个
        if (a.rbegin()[1] == n - 1) {
            /*
(>>> 47)[k]: [6]
(>>> 48)[cnt]: [5]
(>>> 49)[a]: [{8, 2, 3, 4, 5, 6, 1, 7}]
            */
            // 倒数第二个元素没有被交换过，此时不能直接倒数两个元素做交换使得总数加一
            // 需要另寻他法
            // 改成：恢复默认顺序，然后将末尾两个元素换掉
            swap(a.begin()[0], a.rbegin()[0]);
            // 恢复，因为执行两轮以上的话，就不会进入这个 if 了
            swap(a.rbegin()[0], a.rbegin()[1]);
            // 然后交换末尾两个元素，使得总数等于 桥梁个数减一
        } else {
            swap(a.rbegin()[0], a.rbegin()[1]);
            // 交换末尾两个元素，使得递增对数量再加一。
        }
    }
    for (int i = 0; i < n; i++) {
        cout << std::format("{0} ", a[i]);
    }
    auto check = [&]() -> bool {
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) cnt += 1;
        }
        if (cnt != k) {
            dbg(k);
            dbg(cnt);
            dbg(a);
        } else {
            dbg("SUCCESS");
        }
        if (cnt != k) return false;
        return true;
    };
    // assert(check() == true);
    cout << std::format("\n");
    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}
/*

*/