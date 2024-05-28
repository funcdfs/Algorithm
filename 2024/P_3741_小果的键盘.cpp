/**
 * author: https://github.com/funcdfs
 * created: 2024-04-20 19:20:34
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
    string s = "";
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'V' and s[i + 1] == 'K') {
            s[i] = 'X';
            s[i + 1] = 'X';
            cnt += 1;
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'V' and s[i + 1] == 'V' or s[i] == 'K' and s[i + 1] == 'K') {
            cnt += 1;
            break;
        }
    }
    cout << cnt << endl;
    
    return 0;
}
/*

*/