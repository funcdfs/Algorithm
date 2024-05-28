# problem: https://codeforces.com/contest/1167/problem/C
# created: https://github.com/funcdfs 2024/5/24 00:37:34

import sys


# region solve
# ------------------------------------------------------------


class DSU:
    def __init__(self, n):
        self.f = [i for i in range(n)]
        self.siz = [1] * (n)

    def find(self, x):
        while x != self.f[x]:
            self.f[x] = self.f[self.f[x]]
            x = self.f[x]
        return x

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def merge(self, x, y):
        x = self.find(x)
        y = self.find(y)
        if x == y:
            return False
        self.siz[x] += self.siz[y]
        self.f[y] = x
        return True

    def size(self, x):
        return self.siz[self.find(x)]


def solve() -> None:
    n, m = input_multi_int()
    dsu = DSU(n)
    for _ in range(m):
        line = list(input_multi_int())
        k = line[0]
        a = line[1:]
        for i in range(k):
            a[i] -= 1
        for i in range(1, k):
            dsu.merge(a[0], a[i])
    for i in range(n):
        printx(dsu.size(i))


# ------------------------------------------------------------
# endregion solve


# region fastIO
input_int = lambda: int(input_str())  # noqa: E731
input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_list = lambda: map(int, input_str().split())  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
printx = lambda *args: sys.stdout.write(" ".join(map(str, args)) + " ")  # noqa: E731
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731
# endregion fastIO


# region main
solve()
# endregion main
