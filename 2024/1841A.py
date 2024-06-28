# link: https://codeforces.com/contest/1841/problem/A A. Game with Board
# time: 2024/6/12 12:13:30 https://github.com/funcdfs

import sys


# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    
    n = input_int()
    if n >= 5:
        print("Alice")
    else:
        print("Bob")

# ------------------------------------------------------------


# region fastIO
input_int = lambda: int(input_str())  # noqa: E731
input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
input_list = lambda: list(map(int, input_str().split()))  # noqa: E731
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731
# endregion fastIO

# region main
testCase = input_int()
for _case in range(1, testCase + 1):
    solve(_case)  # multi cases with _case info
# endregion main
