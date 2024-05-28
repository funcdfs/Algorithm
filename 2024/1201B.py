# problem: https://codeforces.com/contest/1201/problem/B
# created: https://github.com/funcdfs 2024/5/27 10:46:59 

import sys


# region solve
# ------------------------------------------------------------
def solve() -> None:
    n = input_int()
    a = input_list()
    tot = sum(x for x in a)
    if tot % 2:
        print("NO")
        return
    

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
