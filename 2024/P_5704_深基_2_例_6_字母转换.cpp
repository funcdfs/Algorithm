/**
 * author: https://github.com/funcdfs
 * created: 2024-03-01 15:34:44
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
    
    int diff = 'A' - 'a';
    char c = ' ';
    cin >> c;
    cout << char(c + diff) << endl;
    
    return 0;
}
/*

*/