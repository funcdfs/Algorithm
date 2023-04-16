/**
 * author: https://github.com/fengwei2002
 * created: 2023-04-16 17:38:38
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

using i64 = long long;
i64 mul(i64 a, i64 b, i64 p) {
    i64 ans = 0;
    for (; b > 0; b = b >> 1) {
        if (b & 1) ans = (ans + a) % p;
        a = (a * 2) % p;
    }
    return ans;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    int a = 0, b = 0, p = 0;
    cin >> a >> b >> p;
    // a * b mod p
    cout << mul(a, b, p) << '\n';
    return 0;
}
/*

*/