/**
 * author: https://github.com/funcdfs
 * created: 2024-04-21 22:45:30
 **/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

int qmi(int a, int b, int p) {
    // calculate (a ^ b) mod p
    int ans = 1 % p;
    for (; b; b >>= 1) {
        if (b & 1) {
            ans = (int64_t)ans * a % p;
        }
        a = (int64_t)a * a % p;
    }
    return ans;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;
    cout << qmi(a, b, c) << '\n';
    return 0;

    return 0;
}
/*

*/