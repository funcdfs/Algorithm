# problem: https://codeforces.com/contest/1520/problem/E
# created: https://github.com/funcdfs 2024/5/26 12:46:00

import sys


# region solve
# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    n = input_int()
    s = list(input_str())
    a = []
    idx = 0
    for i in range(n):
        if s[i] == ".":
            idx += 1
        else:
            a.append(idx)
    mid = (len(a) - 1) // 2
    ans = 0
    for x in a:
        ans += abs(x - a[mid])
    print(ans)


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
