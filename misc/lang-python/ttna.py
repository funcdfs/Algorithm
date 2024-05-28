import sys


# region solve
# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    n = input_int()
    a = input_list()
    

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
