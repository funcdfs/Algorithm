/**
 * author: https://github.com/funcdfs
 * created: 2024-03-01 15:37:34
**/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    
    double total = 0, man = 0;
    cin >> total >> man;
    cout << setprecision(3) << fixed << total/ man;
    cout << '\n';
    cout << int(man) * 2;
    return 0;
}
/*

*/