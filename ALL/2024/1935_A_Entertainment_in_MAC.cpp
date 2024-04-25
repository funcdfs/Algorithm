/**
 * author: https://github.com/funcdfs
 * created: 2024-04-25 17:04:02
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
    
    int tt = 0;
    cin >> tt;
    while (tt--) {
        int n = 0;
        cin >> n;
        string s;
        cin >> s;
        string t = ranges::reverse(s);
        cout << min(s, t) << endl;
    }
    
    return 0;
}
/*

*/