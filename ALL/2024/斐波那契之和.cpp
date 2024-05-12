#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int n = 0;
    cin >> n;

    vector<int64_t> fib, s;
    fib.push_back(1), fib.push_back(1);
    s.push_back(1), s.push_back(2);
    for (int i = 2; fib[i - 1] + fib[i - 2] <= 1e8; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
        s.push_back(fib[i] + s[i - 1]);
    }
    int ans = 0;
    auto dfs = [&](auto self, int idx, int nowSum) -> void {
        if (nowSum == n) {
            ans += 1;
            return;
        }
        if (idx == 0) return;
        if (nowSum + fib[idx] <= n) {
            self(self, idx - 1, nowSum + fib[idx]);
        }
        if (nowSum + s[idx - 1] >= n) {
            self(self, idx - 1, nowSum);
        }
    };
    dfs(dfs, (int)fib.size() - 1, 0);

    cout << ans << endl;
    
    return 0;
}
/*

*/