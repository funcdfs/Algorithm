/**
 * name: D. Another Problem About Dividing Numbers
 * link: https://codeforces.com/problemset/problem/1538/D
 * time: 2024/5/19 20:57:11 https://github.com/funcdfs
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
    
    int a = 0, b = 0, k = 0;
    cin >> a >> b >> k;

    auto check = [&]() -> bool {
        
    };

    if (check()) {
        cout << format("Yes\n");
    } else {
        cout << format("No\n");
    }
    
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
给定两个整数 $a$ 和 $b$ 。在一轮中，您可以执行以下操作之一：

- 取一个整数 $c$ ( $c &gt; 1$ 和 **$a$ 应能被 $c$** 整除)并将 $a$ 替换为 $\frac{a}{c}$ ；
- 取一个整数 $c$ ( $c &gt; 1$ 和 **$b$ 应能被 $c$** 整除)，并将 $b$ 替换为 $\frac{b}{c}$ 。

您的目标是恰好使用 $k$ 圈使 $a$ 等于 $b$ 。

例如，在 $4$ 步中，数字 $a=36$ 和 $b=48$ 可以相等：

- $c=6$ ，将 $b$ 除以 $c$ $\Rightarrow$ $a=36$ ， $b=8$ ；
- $c=2$ ，将 $a$ 除以 $c$ $\Rightarrow$ $a=18$ ， $b=8$ ；
- $c=9$ ，将 $a$ 除以 $c$ $\Rightarrow$ $a=2$ ， $b=8$ ；
- $c=4$ ，将 $b$ 除以 $c$ $\Rightarrow$ $a=2$ ， $b=2$ 。

对于给定的数字 $a$ 和 $b$ ，确定是否可以通过恰好使用 $k$ 圈使它们相等。

*/