# problem: https://atcoder.jp/contests/abc355/tasks/abc355_b
# created: https://github.com/funcdfs 2024/5/26 00:13:09

import collections
import sys


# region solve
# ------------------------------------------------------------
def solve() -> None:
    N, M = input_multi_int()
    A = input_list()
    B = input_list()
    C = A + B
    A.sort()
    hs = collections.Counter()
    for i in range(len(A) - 1):
        hs[tuple([A[i], A[i + 1]])] += 1
    C.sort()
    for i in range(len(C) - 1):
        if hs[tuple([C[i], C[i + 1]])] > 0:
            print("Yes")
            return
    print("No")


# ------------------------------------------------------------
# endregion solve


# region main
input_int = lambda: int(input_str())  # noqa: E731
input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
input_list = lambda: list(map(int, input_str().split()))  # noqa: E731
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731

solve()
# endregion main
