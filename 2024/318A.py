# link: https://codeforces.com/contest/318/problem/A A. Even Odds
# time: 2024/9/29 18:03:56 https://github.com/funcdfs

import sys


input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_single_int = lambda: int(input_str())  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
input_list = lambda: list(map(int, input_str().split()))  # noqa: E731
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731


# ------------------------------------------------------------
def solve() -> None:
    n, k = input_multi_int()
    cnt = n // 2
    cntOdd = -1
    if n & 1:
        cntOdd = cnt + 1
    else:
        cntOdd = cnt

    if k > cntOdd:
        # even
        k -= cntOdd
        dbg(n, k, cntOdd)
        print(int(2+(k-1)*2))
    else:
        # odd
        print(int(1+(k-1)*2))
# ------------------------------------------------------------

solve()