# problem: https://codeforces.com/contest/1661/problem/B
# created: https://github.com/funcdfs 2024/5/25 15:18:28

import sys


# region solve
# ------------------------------------------------------------
def solve() -> None:
    n = input_int()
    a = input_list()

    def calc(x):
        pos = 15
        for i in range(15 + 1):  # 枚举额外需要的乘法的次数
            if x & (1 << i):
                pos = i
                break
        return 15 - pos

    for i in range(n):
        x = a[i] # 目的是使 a[i] 变成 1 + 15 个零
        ans = 1e8
        for cnt in range(0, 16):  # 枚举加法的次数
            ans = min(ans, cnt + calc((x + cnt) % (32768)))
        print(ans, end=" ")


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
