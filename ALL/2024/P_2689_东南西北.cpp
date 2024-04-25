/**
 * author: https://github.com/funcdfs
 * created: 2024-04-20 19:24:50
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
    
    int x1, y1, x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int T = 0;
    cin >> T;

    int step = 0;

    while (T--) {
        char c = ' ';
        cin >> c;
        if (x1 == x2 and y1 == y2) {
            cout << step <<endl;
            return 0;
        }
        if (c == 'N' and x1 < x2) {
            // 北
            x1 += 1;
            step += 1;
        } else if (c == 'S' and x1 > x2) {
            // 南
            x1 -= 1;
            step += 1;
        } else if (c == 'W' and y1 > y2) {
            y1 -= 1;
            step += 1;
        } else if (c == 'E' and y1 < y2) {
            y1 += 1; 
            step += 1;
        }
    }

    cout << -1 << endl;
    
    return 0;
}
/*

*/