/**
 * name: D. Distinct Split
 * link: https://codeforces.com/contest/1791/problem/D
 * time: 2024/5/17 12:59:20 https://github.com/funcdfs
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

    int n = 0;
    cin >> n;
    string s(n, ' ');
    cin >> s;
    array<int, 26> cnt{0}, pre{0};
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a'] += 1;
    }
    int ans = 0;
    int preCnt = 0;
    dbg(cnt);
    for (int i = 0; i < n; i++) {
        pre[s[i] - 'a'] += 1;
        if (pre[s[i] - 'a'] == 1) {
            preCnt += 1;
        }
        int suffCnt = 0;
        for (char c = 'a'; c <= 'z'; c++) {
            int diff = cnt[c - 'a'] - pre[c - 'a'];
            if (diff) {
                suffCnt += 1;
            }
        }
        dbg(i, preCnt, suffCnt);
        ans = max(ans, preCnt + suffCnt);
    }
    cout << format("{0}\n", ans);
    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);

    int TT = 0;
    cin >> TT;
    for (int _case = 1; _case <= TT; _case++) {
        solve(_case);
    }

    return 0;
}
/*
让我们把字符串 $x$ 的 $f(x)$ 函数表示为该字符串包含的不同字符数。例如
$f(\texttt{abc}) = 3$ 、 $f(\texttt{bbbbb}) = 1$ 和 $f(\texttt{babacaba}) = 3$
。

给定一个字符串 $s$ ，将其拆分成两个非空字符串 $a$ 和 $b$ ，使得 $f(a) + f(b)$
为最大可能字符串。换句话说，找出 $f(a) + f(b)$ 的最大可能值，使得 $a + b = s$
（字符串 $a$ 和字符串 $b$ 的连接等于字符串 $s$ ）。
*/