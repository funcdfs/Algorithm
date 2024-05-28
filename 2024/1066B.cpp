/**
 * name: B. Heaters
 * link: https://codeforces.com/contest/1066/problem/B
 * time: 2024/5/19 14:11:12 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto main() -> int32_t {
    cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);
    int n = 0, r = 0;
    cin >> n >> r;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> warm(n, false);
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        warm[i] = true;
        for (int x = max(0, a[i] - r); x <= min(n - 1, a[i] + r); x++) {
            warm[x] = true;
        }
    }
    int ans = count(warm.begin(), warm.end(), true);
    auto close = [&](int x) -> void {
        int left = max(0, a[x] - r);
        int right = min(n - 1, a[x] + r);
        for (int i = left; i < right; i++) {
            warm[i] = false;
        }
        for (int i = 0; i < n; i++) {
            if (i == x) continue;
            for (int j = max(0, a[i] - r); j < min(n - 1, a[i] + r); j++) {
                warm[i] = true;
            }
        }
        if (count(warm.begin(), warm.end(), false) == 0) {
            ans -= 1;
        }
        return;
    };

    if (count(warm.begin(), warm.end(), false)) {
        cout << format("-1\n");
        return 0;
    } else {
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue;
            close(i);
        }
    }
    cout << format("{0}\n", ans);

    return 0;
}
/*
Vova 的房子是一个由 $n$
元素组成的数组（是的，我认为这是第一个问题，有人住在数组中）。阵列的某些位置有加热器。如果
$i$ 位置有加热器，则数组的第 $i$ 个元素为 $1$ ，否则数组的第 $i$ 个元素为 $0$ 。

每个加热器都有一个值 $r$ （ $r$ 对于所有加热器都相同）。该值意味着位置 $pos$
处的加热器可以加热范围 $[pos - r + 1; pos + r - 1]$ 内的所有元件。

Vova 喜欢一边思考一边在他的房子里走来走去，他讨厌房子的寒冷位置。 Vova
希望打开他的一些加热器，这样他房子的每个部分都将由至少一个加热器加热。

Vova 的目标是加热整个房子（数组的所有元素），即如果 $n = 6$ 、 $r = 2$ 和加热器位于位置
$2$ 和 $5$ ，那么 Vova 可以加热整个房子，如果他打开房子里的所有加热器（然后第一个 $3$
元件将由第一个加热器加热，最后一个 $3$ 元件将由第二个加热器加热）。

最初，所有加热器都关闭。

但从另一方面来说，Vova
并不喜欢为电费支付太多费用。因此，他想打开**最少**数量的加热器，以便他房子的每个元件都至少由一个加热器加热。

你的任务是找到这个数量的加热器，或者说不可能让整个房子变暖​​。



solution：

先把所有加热器都打开，然后在从左到右依次判断这个加热器关闭后整个屋子是否依然被加热，如果依然被加热，则可以关掉这个加热器，反之则不能关掉这个加热器。

*/