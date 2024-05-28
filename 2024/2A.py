# problem: https://codeforces.com/contest/2/problem/A
# created: https://github.com/funcdfs 2024/5/23 18:44:18

import collections
import sys


# region solve
def solve() -> None:
    n = input_single_int()

    hs = collections.Counter()
    queries = []
    for _ in range(n):
        x, v = input_str().split()
        v = int(v)
        queries.append((x, v))
        hs[x] += v
    maxValue = max(hs.values())

    newHs = collections.Counter()
    for x, v in queries:
        newHs[x] += v
        if newHs[x] >= maxValue and hs[x] == maxValue:
            output(x)
            exit()


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
