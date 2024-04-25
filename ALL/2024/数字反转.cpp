/**
 * author: https://github.com/funcdfs
 * created: 2024-04-25 10:51:12
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
    
    string s = "";
    cin >> s;
    reverse(s.begin(), end(s));
    cout << s <<endl;
    
    return 0;
}
/*

*/