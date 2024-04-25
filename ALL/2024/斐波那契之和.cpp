/**
 * author: https://github.com/funcdfs
 * created: 2024-04-09 22:59:53
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

vector<int64_t> fib, s;

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int n = 0;
    cin >> n;

    fib.push_back(1), fib.push_back(1);
    s.push_back(1), s.push_back(2);
    for (int i = 2; fib[i - 1] + fib[i - 2] <= 1e8; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
        s.push_back(fib[i] + s[i - 1]);
    }
    int ans = 0;
    function<void(int, int)> dfs = [&](int idx, int nowSum) {
        if (nowSum == n) {
            ans += 1;
            return;
        }
        if (idx == 0) return;
        if (nowSum + fib[idx] <= n) {
            dfs(idx - 1, nowSum + fib[idx]);
        }
        if (nowSum + s[idx - 1] >= n) {
            dfs(idx - 1, nowSum);
        }
    };

    dfs(fib.size() - 1, 0);
    cout << ans << endl;

    return 0;
}
/*

*/