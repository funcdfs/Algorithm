/**
 * name: D. Find the Different Ones!
 * link: https://codeforces.com/contest/1927/problem/D
 * time: 2024/5/19 13:32:34 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto solve(int _case) -> void {
    dbg(_case);
    int n = 0;
    cin >> n;
    vector<int> a(n + 1, 0), diff(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            diff[i] = diff[i - 1];
        } else {
            diff[i] = i - 1;
        }
    }
    dbg(a, diff);

    int q = 0;
    cin >> q;
    for (int qi = 0, l, r; qi < q; qi++) {
        cin >> l >> r;
        if (diff[r] >= l and r > l) {
            cout << format("{0} {1}\n", diff[r], r);
        } else {
            cout << format("-1 -1\n");
        }
    }
    cout << format("\n");

    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    for (int _case = 1; _case <= TT; _case++) {
        solve(_case);
    }

    return 0;
}
/*
给你一个由 $$$n$$$ 个整数组成的数组 $$$a$$$ 和 $$$q$$$ 个查询。

每个查询由两个整数 $$$l$$$ 和 $$$r$$$ ( $$$1 \le l \le r \le n$$$ )
表示。您的任务是为每个查询找到两个索引 $$$i$$$ 和 $$$j$$$ (或者确定它们不存在)，以便：

- $$$l \le i \le r$$$ ;
- $$$l \le j \le r$$$ ;
- $$$a &#95; i \ne a &#95; j$$$ .

换句话说，对于每个查询，您需要在 $$$a &#95; l, a &#95; {l+1}, \dots, a &#95; r$$$
中找到一对不同的元素，或者报告不存在这样一对元素。
*/