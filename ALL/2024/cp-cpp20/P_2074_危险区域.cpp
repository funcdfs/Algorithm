/**
 * name: P2074 危险区域
 * link: https://www.luogu.com.cn/problem/P2074
 * time: 2024/5/16 17:46:26 https://github.com/funcdfs
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

    int n, m, k, t;
    cin >> n >> m >> k >> t;

    int x = 0, y = 0;
    int64_t ans = 0;
    for (int kk = 0; kk < k; kk++) {
        cin >> x >> y;
        auto influence = [&]() -> int64_t {
            int res = 0;
            for (int i = max(1, x - t); i <= min(n, x + t); i++) {
                for (int j = max(1, y - t); j <= min(m, y + t); j++) {
                    double dist = sqrt(pow(i - x, 2) + pow(j - y, 2));
                    res += (dist <= t);
                }
            }
            return res;
        };
        ans = max(ans, influence());
    }
    cout << format("{0}\n", ans);

    return 0;
}
/*

*/