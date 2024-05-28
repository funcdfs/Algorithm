# problem: https://codeforces.com/contest/27/problem/B
# created: https://github.com/funcdfs 2024/5/24 12:20:50

import collections
import sys


# region solve
# ------------------------------------------------------------
def solve() -> None:
    n = input_int()
    d = collections.Counter()
    win = collections.Counter()
    for i in range(1, (n - 1) * n // 2):
        x, y = input_multi_int()
        d[x] += 1
        d[y] += 1
        win[x] += 1
    ans = []
    for i in range(1, n + 1):
        if d[i] != (n - 1):
            ans.append(i)
    if win[ans[0]] > win[ans[1]]:
        printx(ans[0], ans[1])
    else:
        printx(ans[1], ans[0])


# ------------------------------------------------------------
# endregion solve


# region fastIO
input_int = lambda: int(input_str())  # noqa: E731
input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
input_list = lambda: list(map(int, input_str().split()))  # noqa: E731
printx = lambda *args: sys.stdout.write(" ".join(map(str, args)) + " ")  # noqa: E731
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731
# endregion fastIO


# region main
solve()
# endregion main
