# problem: https://codeforces.com/contest/1788/problem/C
# created: https://github.com/funcdfs 2024/5/25 22:07:47

import sys


# region solve
# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    n = input_int()

    def check():
        if n % 2 == 0:
            return False
        print("YES")
        d = (n + 1) // 2
        for i in range(d):
            print(i + 1, 2 * n - d + i + 1)
        for i in range(n - d):
            print(i + d + 1, n + 1 + i)
        pass

    if check() is False:
        print("No")


# ------------------------------------------------------------
# endregion solve


# region main
input_int = lambda: int(input_str())  # noqa: E731
input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
input_list = lambda: list(map(int, input_str().split()))  # noqa: E731
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731

testCase = input_int()
for _case in range(1, testCase + 1):
    solve(_case)  # multi cases with _case info
# endregion main
