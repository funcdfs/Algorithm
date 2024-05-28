# problem: https://codeforces.com/contest/377/problem/A
# created: https://github.com/funcdfs 2024/5/24 00:42:40

import sys

from types import GeneratorType


# region bootdfs
# method from https://pyrival.readthedocs.io/en/latest/bootstrap.html
def bootdfs(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc


# endregion bootdfs


# region solve
# ------------------------------------------------------------
def solve() -> None:
    n, m, k = input_multi_int()
    g = [list(input_str()) for _ in range(n)]
    tot = sum(line.count(".") for line in g)
    k = tot - k
    for i in range(n):
        for j in range(m):
            if g[i][j] == ".":
                g[i][j] = "X"

    directions = [(0, -1), (-1, 0), (0, 1), (1, 0)]

    @bootdfs
    def dfs(x, y):
        nonlocal k, g
        if k <= 0:
            yield
        g[x][y] = "."
        k -= 1
        for dx, dy in directions:
            tx, ty = x + dx, y + dy
            if 0 <= tx < n and 0 <= ty < m and g[tx][ty] == "X" and k > 0:
                yield dfs(tx, ty)
        yield

    for i in range(n):
        for j in range(m):
            if g[i][j] == "X":
                dfs(i, j)
                for line in g:
                    print(*line, sep="")
                exit()


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
