import copy
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
def solve() -> None:
    n = input_single_int()
    ans = []
    st = [False] * n

    @bootdfs
    def dfs(now):
        if len(now) == n:
            ansItem = copy.deepcopy(now)
            ans.append(ansItem)
            yield
        for i in range(n):
            if st[i] is True:
                continue
            st[i] = True
            now.append(i + 1)
            yield dfs(now)
            now.pop()
            st[i] = False
        yield

    dfs([])
    for ansItem in ans:
        output(*ansItem)


# endregion solve


# region fastIO
dbg = lambda *args: sys.stderr.write(" ".join(map(str, args)) + "\n")  # noqa: E731
output = lambda *args: sys.stdout.write(" ".join(map(str, args)) + "\n")  # noqa: E731
input_str = lambda: sys.stdin.readline().rstrip()  # noqa: E731
input_single_int = lambda: int(input_str())  # noqa: E731
input_multi_int = lambda: map(int, input_str().split())  # noqa: E731
input_list = lambda: list(map(int, input_str().split()))  # noqa: E731
# endregion fastIO


# region main
solve()
# endregion main
