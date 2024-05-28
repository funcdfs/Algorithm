# problem: https://atcoder.jp/contests/abc161/tasks/abc161_c
# created: https://github.com/funcdfs 2024/5/28 23:41:41 

import sys


# region solve
# ------------------------------------------------------------
def solve() -> None:
    n, k = input_multi_int()
    if n >= k:
        x = n // k
        if n % k:
            x += 1
        print(x * k - n)
    else:
        print(n)

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
