/**
 * name: A. Make it White
 * link: https://codeforces.com/contest/1927/problem/A
 * time: 2024/5/19 14:03:56 https://github.com/funcdfs
 **/


#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */



auto solve(int _case) -> void {
    dbg(_case);
    
    int len = 0;
    cin >> len;
    string s(len, ' ');
    cin >> s;

    int left = 0;
    int right = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'B') {
            left = i;
            break;
        }
    }
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == 'B') {
            right = i;
            break;
        }
    }
    
    cout << format("{0}\n", right - left + 1);
    
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
您有一个由 $n$ 单元格组成的水平条带。每个单元格要么是白色的，要么是黑色的。

您可以选择一次**连续**的单元格段并将它们全部涂成白色。执行此操作后，该段中的所有黑色单元格将变为白色，而白色单元格将保持白色。

为了使所有 $n$ 单元格变成白色，需要涂成白色的线段的最小长度是多少？
*/