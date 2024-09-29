# link: https://codeforces.com/contest/630/problem/A A. Again Twenty Five!
# time: 2024/9/29 18:36:00 https://github.com/funcdfs

import sys


input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_single_int = lambda: int(input_str())  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
input_list = lambda: list(map(int, input_str().split()))  # noqa: E731
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731


# ------------------------------------------------------------
def solve() -> None:
    n = input_single_int()
    x = pow(5, n)
    print(x % 100)

# ------------------------------------------------------------

solve()