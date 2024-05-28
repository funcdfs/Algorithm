/**
 * author: https://github.com/funcdfs
 * created: 2024-03-01 15:29:54
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

    int n = 5;
    int x = n / 2;
    for (int i = 0; i <= n / 2; i++) {
        if (x < 0) break;
        for (int j = 0; j < x; j++) {
            cout << ' ';
        }
        for (int j = 0; j < (n - 2 * x); j++) {
            cout << s;
        }
        for (int j = 0; j < x;j ++) {
            cout << ' ';
        }
        cout << '\n';
        x -= 1;
    }
    
    return 0;
}
/*

*/