/**
 * author: https://github.com/funcdfs
 * created: 2024-04-20 19:06:07
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
    
    int n = 0;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    int tot = 0;

    unordered_map<int, int> hs;
    for (int i = 0; i < n; i++) {
        if (hs.contains(a[i]) == false) {
            tot += 5;
        }
        hs[a[i]] = 1;
        tot += 1;
    }    
    
    int maxVal = *max_element(a.begin(), a.end());
    tot += 10 * maxVal;
    
    cout << tot << endl;

    return 0;
}
/*

*/