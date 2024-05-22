/**
 * name: Gold Rush
 * link: https://www.luogu.com.cn/problem/CF1829D
 * time: 2024/5/17 16:02:55 https://github.com/funcdfs
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

    int n = 0, m = 0;
    cin >> n >> m;

    auto check = [&]() -> bool {
        stack<int> stk;
        stk.push(n);

        while (not stk.empty()) {
            auto t = stk.top();
            stk.pop();

            if (t == m) {
                return true;
            }
            if (t % 3 == 0) {
                stk.push(t / 3 * 2);
                stk.push(t / 3);
            }
        }
        return false;
    };
    if (check()) {
        cout << format("YES\n");
    } else {
        cout << format("NO\n");
    }

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

*/