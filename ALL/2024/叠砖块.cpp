/**
 * author: https://github.com/funcdfs
 * created: 2024-04-27 19:00:58
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
    
    int n = 0;
    cin >> n;
    int sum = 0;
    for (int i  = 0; i < n;i ++) {
        sum += i + 1;
    }

cout << sum << endl;
    return 0;
}
/*

*/