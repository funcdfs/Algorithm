# problem: https://codeforces.com/contest/1969/problem/A
# created: https://github.com/funcdfs 2024/5/27 21:40:06

import sys


# region solve
# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    _ = input_int()
    nums = input_list()
    
    for i, p in enumerate(nums, 1):
        if i == nums[p - 1]:
            print(2)
            return
    print(3)


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
