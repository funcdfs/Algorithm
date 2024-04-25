/**
 * author: https://github.com/funcdfs
 * created: 2024-04-09 12:27:39
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

    // 火鸡的数量
    int n = 0;
    while (cin >> n) {
        string price = "xxxxx";
        // 五位数中间的三位数字。
        cin >> price[1] >> price[2] >> price[3];
        bool end = false;
        for (int i = 9; i > 0; i--) {
            for (int j = 9; j >= 0; j--) {
                price[0] = i + '0';
                price[4] = j + '0';
                int p = stoi(price);
                if (p % n == 0) {
                    end = true;
                    cout << price.front() << ' ' << price.back() << ' ' << int(p / n) << endl;
                }
                if (end == true) break;
            }
            if (end == true) break;
        }
        if (end == false) {
            price = "0";
            cout << price << endl;
        }
    }

    return 0;
}
/*

*/