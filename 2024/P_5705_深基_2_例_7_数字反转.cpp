/**
 * author: https://github.com/funcdfs
 * created: 2024-03-01 15:36:32
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
    
    string s = "";
    cin >> s;
    reverse(s.begin(), s.end());
    cout << s << endl;
    
    return 0;
}
/*

*/