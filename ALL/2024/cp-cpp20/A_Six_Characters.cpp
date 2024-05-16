/**
 * author:  https://github.com/funcdfs
 * problem: https://atcoder.jp/contests/abc251/tasks/abc251_a
 * created: 4/30/2024, 1:39:44 PM	
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
    
    string s;
    cin >>s;
    for (int i = 0; i < 6; i++){
        cout << s[i % (int)s.size()];
    }
    
    return 0;
}
/*

*/