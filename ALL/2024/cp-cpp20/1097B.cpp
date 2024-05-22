/**
 * name: B. Petr and a Combination Lock
 * link: https://codeforces.com/contest/1097/problem/B
 * time: 2024/5/17 13:39:25 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

auto solve() -> void {
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto check = [&]() -> bool {
        for (int t = 0; t < (1 << n); t++) {
            int x = 0;
            for (int i = 0; i < n; i++) {
                if (t & (1 << i)) {
                    x += a[i];
                } else {
                    x -= a[i];
                }
            }
            if (x % 360 == 0) {
                return true;
            }
        }
        return false;
    };

    if (check()) {
        cout << format("YES\n");
        return;
    } else {
        cout << format("NO\n");
        return;
    }

    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    solve();

    return 0;
}
/*
彼得刚买了一辆新车。他刚到彼得堡最有名的加油站加油，突然发现油箱上有一把密码锁！这把锁的刻度为
$360$ 度，指针最初指向零：

![](https://espresso.codeforces.com/13b9223256038b68e54be700f46943f507ee6484.png)

彼得打电话给他的汽车经销商，经销商指示他将锁的转轮准确旋转 $n$ 次。 $i$
/次旋转应该是 $a_i$ 度，可以是顺时针，也可以是逆时针，在所有 $n$
次旋转之后，指针应该再次指向零。

这让 Petr
有点困惑，因为他不确定哪些应该顺时针旋转，哪些应该逆时针旋转。由于有许多可能的旋转锁的方法，请帮助他找出是否存在至少一种方法，使所有
$n$ 旋转后指针再次指向零。
*/