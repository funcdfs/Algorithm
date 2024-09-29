# link: https://codeforces.com/contest/1328/problem/A A. Divisibility Problem
# time: 2024/9/29 18:13:53 https://github.com/funcdfs

import sys

input_str = lambda: sys.stdin.readline().rstrip()
input_single_int = lambda: int(input_str())
input_multi_int = lambda: map(int, input_str().split())
input_list = lambda: list(map(int, input_str().split()))
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")

# ------------------------------------------------------------
def solve(_case) -> None:
    #dbg("# Case: ", _case)
    a, b = input_multi_int()
    if b > a:
        print(b-a)
    else:
        left = a//b
        right = a//b + 1
        if left* b == a:
            print(0)
        else:
            print(right*b-a)
        # print(abs(min(left, right)*b-a))


# ------------------------------------------------------------


for _case in range(1, input_single_int() + 1):
     solve(_case)  # multi cases with _case info
