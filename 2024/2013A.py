# link: https://codeforces.com/contest/2013/problem/A A. Zhan's Blender
# time: 2024/9/29 17:50:10 https://github.com/funcdfs

import sys

input_str = lambda: sys.stdin.readline().rstrip()
input_single_int = lambda: int(input_str())
input_multi_int = lambda: map(int, input_str().split())
input_list = lambda: list(map(int, input_str().split()))
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")


# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    n = input_single_int()
    x, y = input_multi_int()
    c = min(x, y)
    print((n + c - 1) // c)


# ------------------------------------------------------------


for _case in range(1, input_single_int() + 1):
    solve(_case)  # multi cases with _case info
