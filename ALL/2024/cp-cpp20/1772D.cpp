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
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    auto check = [&]() -> bool {
        int minVal = 0, maxVal = (int)1e9;
        for (int i = 0; i + 1 < n; i++) {
            int x = a[i];
            int y = a[i + 1];
            int midL = (x + y) / 2;
            int midR = (x + y + 1) / 2;
            if (x < y) {
                maxVal = min(maxVal, midL)
            }
            if (x > y) {
                minVal = max(minVal, midR);
            }
        }
        if (minVal <= maxVal) {
            cout << format("{0}\n", minVal);
            return true;
        }
        return false;
    };

    if (check() == false) {
        cout << format("-1\n");
    }
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
给您一个由 $n$ 整数组成的数组 $a$ 。如果 $a_1 \le a_2 \le \dots \le a_n$ ，则数组已排序。

您希望通过应用以下操作**恰好一次**来对数组 $a$ 进行排序：

- 选择一个整数 $x$ ，然后对于每个 $i \in [1, n]$ ，将 $a_i$ 替换为 $|a_i - x|$ 。

查找 $x$ 中任何可使数组排序的值，或者报告不存在这样的值。
*/