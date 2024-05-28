# problem: https://codeforces.com/contest/1371/problem/C
# created: https://github.com/funcdfs 2024/5/24 13:18:42

import sys


# region solve
# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    a, b, n, m = input_multi_int()
    if (a + b) < (n + m):
        print("No")
        return
    if min(a, b) < m:
        print("No")
        return
    else:
        print("Yes", "No")
        return


# ------------------------------------------------------------
# endregion solve


# region main
input_int = lambda: int(input_str())  # noqa: E731
input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
input_list = lambda: list(map(int, input_str().split()))  # noqa: E731

testCase = input_int()
for _case in range(1, testCase + 1):
    solve(_case)  # multi cases with _case info
# endregion main
