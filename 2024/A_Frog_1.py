# problem: https://atcoder.jp/contests/dp/tasks/dp_a
# created: https://github.com/funcdfs 2024/5/24 14:56:23

import sys


# region solve
# ------------------------------------------------------------
def solve() -> None:
    n = input_int()
    h = input_list()
    h = [0] + h
    f = [0] * (n + 1)
    f[2] = abs(h[2] - h[1])
    for i in range(3, n + 1):
        f[i] = min(f[i - 2] + abs(h[i] - h[i - 2]), f[i - 1] + abs(h[i] - h[i - 1]))
    print(f[n])
    exit()


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
