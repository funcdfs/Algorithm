# problem: https://codeforces.com/contest/1487/problem/C
# created: https://github.com/funcdfs 2024/5/24 10:55:36

import sys


# region solve
# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    n = input_int()
    for i in range(1, n):
        j = i +1
        if n &1 

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
testCase = input_int()
for _case in range(1, testCase + 1):
    solve(_case)  # multi cases with _case info
# endregion main
