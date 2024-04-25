/**
 * author: https://github.com/funcdfs
 * created: 2024-04-13 12:30:57
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
    
    int n, b, p;
    cin >> n >> b >> p;
    // n + 1
    int64_t sum = 0;
    sum += (n - 1) * (2 * b + 1);
    
    cout << sum << n * p << endl;
    
    return 0;
}
/*

*/