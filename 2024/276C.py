# problem: https://codeforces.com/contest/276/problem/C
# created: https://github.com/funcdfs 2024/5/23 15:48:17

import sys


# region solve
def solve() -> None:
    dbg(1)


# endregion solve


# region fastIO
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731
output = lambda *args: sys.stdout.write(" ".join(map(str, args)) + "\n")  # noqa: E731
input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_single_int = lambda: int(input_str())  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
input_list = lambda: list(map(int, input_str().split()))  # noqa: E731
# endregion fastIO


# region main
solve()
# endregion main
