# problem: https://open.kattis.com/problems/tilhamingju
# created: https://github.com/funcdfs 2024/5/24 17:02:58 

import sys


# region solve
# ------------------------------------------------------------
def solve() -> None:
    print("TIL HAMINGJU MED AFMAELID FORRITUNARKEPPNI FRAMHALDSSKOLANNA!")

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
