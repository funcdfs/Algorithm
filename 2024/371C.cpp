/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/371/problem/C
 * created: 5/7/2024, 11:02:20 PM	
**/

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

    string s = "";
    vector<int> cnt(3, 0), price(3, 0), satisfy(3, 0);
    int64_t money = 0;

    cin >> s;
    for (int i = 0; i < 3; i++) cin >> cnt[i];
    for (int i = 0; i < 3; i++) cin >> price[i];
    cin >> money;

    for (auto& c : s) {
        if (c == 'B') satisfy[0] += 1;
        else if (c == 'S') satisfy[1] += 1;
        else if (c == 'C') satisfy[2] += 1;
    }

    auto check = [&](int64_t x) -> bool {
        int64_t tot = 0;
        for (int i = 0; i < 3; i++) {
            int64_t num = satisfy[i] * x;
            int64_t buyPart = max((int64_t)0, num - cnt[i]);
            tot += buyPart * price[i];
            if (tot > money) return false;
        }
        return tot <= money;
    };

    int64_t l = 0, r = money + *max_element(cnt.begin(), cnt.end()) + 2;

    while (l < r){
        int64_t mid = (l + r + 1) >> 1;
        dbg(mid);
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << r << endl;

    return 0;
}
/*

*/