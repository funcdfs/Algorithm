# problem: https://codeforces.com/contest/1470/problem/A
# created: https://github.com/funcdfs 2024/5/24 13:11:16

import copy
import sys


# region solve
# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    n, m = input_multi_int()
    k = input_list()  # idx
    c = input_list()  # cost

    order = copy.deepcopy(k)
    order.sort(reverse=True)

    ans = now = 0
    for i in range(n):
        if c[now] < c[order[i] - 1]:
            ans += c[now]
            now += 1
        else:
            ans += c[order[i] - 1]
    printn(ans)


# ------------------------------------------------------------
# endregion solve


# region fastIO
input_int = lambda: int(input_str())  # noqa: E731
input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
input_list = lambda: list(map(int, input_str().split()))  # noqa: E731
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731
printx = lambda *args: sys.stdout.write(" ".join(map(str, args)) + " ")  # noqa: E731
printn = lambda *args: sys.stdout.write(" ".join(map(str, args)) + "\n")  # noqa: E731
# endregion fastIO


# region main
testCase = input_int()
for _case in range(1, testCase + 1):
    solve(_case)  # multi cases with _case info
# endregion main
