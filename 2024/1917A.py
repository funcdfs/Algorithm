import sys


# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    n = input_int()
    a = input_list()
    
    pow = 1
    for i in range(len(a)):
        pow *= a[i]
    if pow <= 0:
        print(0)
    else:
        print(1)
        print(1, 0)


# ------------------------------------------------------------


# region fastIO
input_int = lambda: int(input_str())  # noqa: E731
input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
input_list = lambda: list(map(int, input_str().split()))  # noqa: E731
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731
# endregion fastIO

# region main
testCase = input_int()
for _case in range(1, testCase + 1):
    solve(_case)  # multi cases with _case info
# endregion main
