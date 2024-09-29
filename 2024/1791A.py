# link: https://codeforces.com/contest/1791/problem/A A. Codeforces Checking
# time: 2024/9/29 18:52:29 https://github.com/funcdfs

import sys


input_str = lambda: sys.stdin.readline().rstrip()
input_single_int = lambda: int(input_str())
input_multi_int = lambda: map(int, input_str().split())
input_list = lambda: list(map(int, input_str().split()))
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")
println = lambda *args: sys.stdout.write(" ".join(map(str, args)) + "\n")


# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    s = input_str()
    cf = "codeforces"
    if s in cf:
        println("YES")
    else:
        println("NO")


# ------------------------------------------------------------


for _case in range(1, input_single_int() + 1):
    solve(_case)  # multi cases with _case info
