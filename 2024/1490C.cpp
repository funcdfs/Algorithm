/**
 * name: C. Sum of Cubes
 * link: https://codeforces.com/contest/1490/problem/C
 * time: 2024/5/17 12:40:30 https://github.com/funcdfs
 **/

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/dbg.h"
#else
#define dbg(...) 1
#endif /* https://gist.github.com/funcdfs */


#define int64_t unsigned long long

const int64_t N = 1e14;

unordered_set<int64_t> cubes;

void pre() {
    for (int64_t i = 1; i * i * i <= N; i++) {
        cubes.insert(i * i * i);
    }
}
auto solve(int _case) -> void {
    dbg(_case);

    int64_t x = 0;
    cin >> x;

    for (int64_t i = 1; i * i * i <= x; i++) {
        if (cubes.contains(x - i * i * i)) {
            cout << format("YES\n");
            return;
        }
    }

    cout << format("NO\n");

    return;
}

auto main() -> int32_t {
    cin.tie(nullptr), ios::sync_with_stdio(false);
    pre();
    int TT = 0;
    cin >> TT;
    for (int _case = 1; _case <= TT; _case++) {
        solve(_case);
    }

    return 0;
}
/*
给你一个正整数 $$$x$$$ 。请检验数字 $$$x$$$ 是否可以表示为两个正整数的立方之和。

从形式上说，你需要检验是否有两个整数 $$$a$$$ 和 $$$b$$$ ( $$$1 \le a, b$$$ )使得
$$$a^3+b^3=x$$$ .

例如，如果是 $$$x = 35$$$ ，那么数字 $$$a=2$$$ 和 $$$b=3$$$ 是合适的(
$$$2^3+3^3=8+27=35$$$ )。如果是 $$$x=4$$$ ，那么没有一对数字 $$$a$$$ 和 $$$b$$$
是合适的。
*/