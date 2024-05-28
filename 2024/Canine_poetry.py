import collections
import sys


# region solve
# ------------------------------------------------------------
def solve() -> None:
    s = list(input_str())
    hs = collections.defaultdict()
    for i in range(len(s)):
        hs[i + 1] = s[i]
    ans = 0
    for k, v in hs:
        if hs.get(v):
            ans += 1
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
