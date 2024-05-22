/**
 * name: B. Yet Another Palindrome Problem
 * link: https://codeforces.com/contest/1324/problem/B
 * time: 2024/5/17 12:47:45 https://github.com/funcdfs
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
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];

    // 长度至少为 3 的子序列是回文
    auto check = [&]() -> bool {
        unordered_map<int, int> hs;
        hs[a[0]] = 1;
        for (int i = 1; i < n; i++) {
            if (hs.contains(a[i]) and a[i - 1] != a[i]) {
                return true;
            }
            hs[a[i]] += 1;
            if (hs[a[i]] >= 3) {
                return true;
            }
        }
        return false;
    };
    if (check()) {
        cout << format("YES\n");
    } else {
        cout << format("NO\n");
    }

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

给你一个由 $n$ 个整数组成的数组 $a$ 。

你的任务是判断 $a$ 是否有长度至少为 $3$ 的**子序列**是回文。

回想一下，如果从 $a$
中移除一些（可能是零）元素（不一定是连续的），而不改变其余元素的顺序，就可以得到
$b$ ，那么数组 $b$ 就叫做数组 $a$ 的**子序列**。例如， $[2]$ 、 $[1, 2, 1, 3]$
和 $[2, 3]$ 是 $[1, 2, 1, 3]$ 的子序列，但 $[1, 1, 2]$ 和 $[4]$ 不是。

此外，我们还可以回顾一下，回文数组是一个反向读法与正向读法相同的数组。换句话说，对于从
$1$ 到 $n$ 的所有 $i$ 来说，长度为 $n$ 的数组 $a$ 如果是 $a_i = a_{n - i - 1}$
，那么 $a_i = a_{n - i - 1}$ 就是回文数组。例如，数组 $[1234]$ 、 $[1, 2, 1]$ 、
$[1, 3, 2, 2, 3, 1]$ 和 $[10, 100, 10]$ 是 palindromes，但数组 $[1, 2]$ 和 $[1,
2, 3, 1]$ 不是。

您必须回答 $t$ 个独立的测试用例。

*/