/**
 * author: https://github.com/funcdfs
 * created: 2024-04-09 21:18:12
 **/

// 小青蛙跳楼梯。

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0;
    cin >> n;
    vector<int> days(n + 1, 0);
    vector<int> costs(4, 0);
    for (int i = 1; i <= n; i++) cin >> days[i];
    for (int i = 1; i <= 3; i++) cin >> costs[i];
    
    auto get = [&](int i, int cnt) -> int {
        int day = i;
        while (day >= 1 && days[day] >= days[i] - cnt + 1) day--;
        return day;
    };
    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] + costs[1];
        f[i] = min(f[i], f[get(i, 7)] + costs[2]);
        f[i] = min(f[i], f[get(i, 30)] + costs[3]);
    }

    cout << f[n] << endl;

    return 0;
}
/*

*/