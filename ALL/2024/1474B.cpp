// LUOGU_RID: 158933373
/**
 * author:  https://github.com/funcdfs
 * problem: https://codeforces.com/contest/1474/problem/B
 * created: 5/13/2024, 9:25:14 PM
 **/

#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL /* For Local Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif

const int inf = 3e6 + 5;
bool primes[inf];
void prepare() {
    auto isPrime = [&](auto x) -> bool {
        if (x < 2) {
            return false;
        }
        for (int i = 2; i * i <= x; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    };
    for (int i = 2; i < inf; i++) {
        if (isPrime(i)) {
            primes[i] = true;
        }
    }
}

auto solve() -> void {
    int d = 0;
    cin >> d;
    auto find = [&](int x) -> int {
        while (primes[x] == false) {
            x += 1;
        }
        assert(primes[x] == true);
        return x;
    };
    int x = find(d + 1);
    int y = find(x + 1);
    dbg(x, y);
    cout << std::format("{0}", (int64_t)x * y);
    cout << std::format("\n");
    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    prepare();
    int TT = 0;
    cin >> TT;
    while (TT--) {
        solve();
    }

    return 0;
}
/*

*/