/**
 * author: https://github.com/funcdfs
 * created: 2024-04-09 18:02:25
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
    
    // 数字 n 能否拆分为阶乘的和。
    // 10! = 3628800
    // 9!  = 326880

    // 1 到 2^10 - 1 中间的每一个数字都对应一种阶乘的选择方式。
    // 从 0 到 9 的阶乘看做 01 背包中的物品，查看是否存在一种方法，使得选择物品的总和为 n

    vector<int> s(10, 1);
    for (int i = 1; i <= 9; i++) {
        s[i] = s[i - 1] * i;
    }
    // 预处理得到十个方案。

    // 然后用 0 1 背包处理所有可能得到的方案，或者二进制枚举所有可能的方案。
    int n = 0;
    bool end = false;
    while (cin >> n and n >= 0) {
        if (n == 0) {
            cout << "NO\n";
            break;
        }
        for (int i = 0; i < (1 << 10); i++) {
            int t = 0;
            for (int j = 0; j < 10; j++) {
                if ((i >> j) & 1) {
                    t += s[j];
                }
                if (t == n) {
                    end = true;
                    cout << "YES\n";
                    break;
                }
            }
            if (end == true) break;
        }
        if (end == false) {
            cout << "NO\n" << endl;
        }
    }
    
    return 0;
}
/*

*/