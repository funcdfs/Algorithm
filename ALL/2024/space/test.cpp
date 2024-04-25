/**
 * author: https://github.com/funcdfs
 * created: 2024-04-24 13:27:06
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

    int64_t a = 0, b = 0, p = 0;
    cin >> a >> b >> p;

    auto multi = [](int64_t a, int64_t b, int64_t p) -> int64_t {
        int64_t ans = 0;
        for (; b > 0; b = b >> 1) {
            if (b & 1) ans = (ans + a) % p;
            a = (a * 2) % p;
        }
        return ans;
    };  // (a 乘 b ) 模 p 的大运算结果。10^18

    cout << multi(a, b, p);

    return 0;
}
/*

*/