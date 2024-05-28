/**
 * name: C. Training Before the Olympiad
 * link: https://codeforces.com/contest/1916/problem/C
 * time: 2024/5/16 15:01:53 https://github.com/funcdfs
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
    array<int, 3> xxx{0};
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    int64_t sum = 0;
    int odd = 0;
    for (int i = 1; i <= n; i++) {
        int x = a[i - 1];
        sum += x, odd += (sum & 1);

        dbg(x, sum);
        if (odd >= 3) {
            int minusCnt = odd / 3;
            odd %= 3;
            sum -= minusCnt;
        } else if (odd == 2) {
            odd -= 2;
        } else if (odd == 1) {
            odd -= 1;
            sum -= 1;
        }
        dbg("final", sum);
        cout << format("{0} ", sum);
    }
    cout << format("\n");

    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    for (int _case = 1; _case <= TT; _case++) {
        solve(_case);
    }

    return 0;
}
/*

首先易得对于每次合并，
只有当一个偶数和一个奇数合并时，它们的总和才会变小，并且合并过后的数必定是偶数。
所以我们可以得到一个结论，
小1 会优先合并奇数和奇数，而小2会优先合并奇数和偶数。

在奇数的数量充足的时候，小1用两个，小2用一个，最后奇数少三个，偶数多一个
    总和 小1选择的方案不变，小2选择结果少了一个。

在奇数的数量不够的时候，也就是不够三个奇数的时候
    两个奇数：
        小1全部用掉，总和不变
    一个奇数：
        谁用都一样，总和少一
*/