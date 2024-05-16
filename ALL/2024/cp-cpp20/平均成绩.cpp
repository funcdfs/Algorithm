/**
 * author: https://github.com/funcdfs
 * created: 2024-04-29 12:50:36
 * 
**/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#ifdef LOCAL /* For Debugging Purposes */
#include "algo/dbg.h"
#else
#define dbg(...) 42
#endif

using ull = unsigned long long int;

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int64_t sum = accumulate(a.begin(), a.end(), int64_t(0));
    int64_t 
    
    return 0;
}
/*

*/