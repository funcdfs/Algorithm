# problem: https://codeforces.com/contest/1037/problem/C
# created: https://github.com/funcdfs 2024/5/25 11:54:22

import sys


# region solve
# ------------------------------------------------------------
def solve() -> None:
    n = input_int()
    a = list(input_str())
    b = list(input_str())
    # make a equal to b
    ans = 0
    for i in range(0, n - 1):
        if a[i] == "0" and a[i + 1] == "1" and b[i] == "1" and b[i + 1] == "0":
            a[i] = b[i]
            a[i + 1] = b[i + 1]
            ans += 1
            i += 1
        elif a[i] == "1" and a[i + 1] == "0" and b[i] == "0" and b[i + 1] == "1":
            a[i] = b[i]
            a[i + 1] = b[i + 1]
            ans += 1
            i += 1
        elif a[i] != b[i]:
            a[i] = b[i]
            ans += 1
    if a[-1] != b[-1]:
        ans += 1
        a[-1] = b[-1]
    # print(a, b)
    print(ans)


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
