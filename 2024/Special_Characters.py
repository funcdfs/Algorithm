# problem: https://vjudge.net/problem/CodeForces-1948A#author=GPT_zh
# created: https://github.com/funcdfs 2024/5/23 13:25:51 

from collections import defaultdict, deque
import sys


# region solve
def solve(_case) -> None:
    DBG("# Case: ", _case)
    n = INT()
    


# endregion solve


# region fastIO
STR = lambda: sys.stdin.readline().rstrip()  # noqa: E731
INT = lambda: int(STR())  # noqa: E731
INTS = lambda: map(int, STR().split())  # noqa: E731
LIST = lambda: list(map(int, STR().split()))  # noqa: E731
DBG = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731
# endregion fastIO


# region main
testCase = INT()
for _case in range(1, testCase + 1):
    solve(_case)  # multi cases with _case info
# endregion main
