# problem: https://codeforces.com/contest/1370/problem/C
# created: https://github.com/funcdfs 2024/5/24 13:41:45

import sys


class PrimeTable:
    def __init__(self, n: int) -> None:
        self.n = n
        self.primes = []
        self.max_div = list(range(n + 1))
        self.max_div[1] = 1
        self.phi = list(range(n + 1))

        for i in range(2, n + 1):
            if self.max_div[i] == i:
                self.primes.append(i)
                for j in range(i, n + 1, i):
                    self.max_div[j] = i
                    self.phi[j] = self.phi[j] // i * (i - 1)

    def is_prime(self, x: int):
        if x < 2:
            return False
        if x <= self.n:
            return self.max_div[x] == x
        for p in self.primes:
            if p * p > x:
                break
            if x % p == 0:
                return False
        return True


pt = PrimeTable(5 * 10**5)


# region solve
# ------------------------------------------------------------
def solve(_case) -> None:
    # dbg("# Case: ", _case)
    n = input_int()
    win = 0
    if n == 1:
        win = 0
    elif n == 2:
        win = 1
    elif n % 2 == 1:
        win = 1
    elif pt.is_prime(n // 2):
        win = 0
    else:
        win = 1
    if win == 1:
        print("Ashishgup")
    else:
        print("FastestFinger")


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
