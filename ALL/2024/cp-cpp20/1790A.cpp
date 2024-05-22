/**
 * name: A. Polycarp and the Day of Pi
 * link: https://codeforces.com/contest/1790/problem/A
 * time: 2024/5/19 14:07:09 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */

string pi = "314159265358979323846264338327";

auto solve(int _case) -> void {
    dbg(_case);

    string s;
    cin >> s;
    int idx = 0;
    while (idx < (int)s.size()) {
        if (s[idx] == pi[idx]) {
            idx += 1;
        } else {
            break;
        }
    }
    cout << format("{0}\n", idx);

    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), cout.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    for (int _case = 1; _case <= TT; _case++) {
        solve(_case);
    }

    return 0;
}
/*
3 月 14 日，全世界都在庆祝数字 $\pi$
的日子。这是一个非常重要的数学常数，等于圆的周长与其直径的比值。

波利卡普在学校被告知，数字 $\pi$
是无理数，因此它的十进制数有无限位数。他想尽可能准确地记住这个数字，为​​数字 $\pi$
的日子做好准备。

波利卡普写下了他能记住的所有数字。例如，如果 Polycarp 将 $\pi$ 记为 $3.1415$ ，他就会写出
31415。

波利卡普 (Polycarp) 很匆忙，可能会犯错误，因此您决定检查波利卡普 (Polycarp)
实际上正确记住了数字 $\pi$ 的前几个数字。
*/