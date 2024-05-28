# problem: https://atcoder.jp/contests/abc355/tasks/abc355_a
# created: https://github.com/funcdfs 2024/5/26 00:09:20 

import sys


# region solve
# ------------------------------------------------------------
def solve() -> None:
    line = list(input_str())
    A = line[0]
    B = line[-1]
    if A == B:
        print(-1)
    else:
        if A > B:
            A, B = B, A
        if A == '1' and B == '2':
            print(3)
        elif A == '2' and B == '3':
            print(1)
        elif A == '1' and B == '3':
            print(2)

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
