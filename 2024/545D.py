# problem: https://codeforces.com/contest/545/problem/D
# created: https://github.com/funcdfs 2024/5/24 12:25:27

import sys


# region solve
# ------------------------------------------------------------
def solve() -> None:
    _ = input_int()
    a = input_list()
    sum = cnt = 0
    a.sort()
    for ai in a:
        if sum <= ai:
            sum += ai
            cnt += 1
    printx(cnt)
    exit()

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
