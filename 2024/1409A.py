# link: https://codeforces.com/contest/1409/problem/A A. Yet Another Two Integers Problem
# time: 2024/9/29 18:57:05 https://github.com/funcdfs

import sys


input_str = lambda: sys.stdin.readline().rstrip()
input_single_int = lambda: int(input_str())
input_multi_int = lambda: map(int, input_str().split())
input_list = lambda: list(map(int, input_str().split()))
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")
println = lambda *args: sys.stdout.write(" ".join(map(str, args)) + "\n")

# ------------------------------------------------------------
def solve(_case) -> None:
    #dbg("# Case: ", _case)
    a, b = input_multi_int()
    if a == b:
        println(0)
    else:
        if b < a:
            a, b = b, a
        left = b-a
        if left % 10:
            println((b-a)//10+1)
        else:
            println(left//10)



# ------------------------------------------------------------


for _case in range(1, input_single_int() + 1):
     solve(_case)  # multi cases with _case info
