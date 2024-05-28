# problem: https://codeforces.com/problemset/problem/4/C
# created: https://github.com/funcdfs 2024/5/23 18:35:14

import collections
import sys

hs = collections.Counter()


# region solve
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    s = input_str()
    if hs.get(s):
        output(s + str(hs[s]))
    else:
        output("OK")
    hs[s] += 1


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
testCase = input_single_int()
for _case in range(1, testCase + 1):
    solve(_case)  # multi cases with _case info
# endregion main
