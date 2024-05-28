# problem: https://www.acwing.com/problem/content/1/
# created: https://github.com/funcdfs 2024/5/15 19:16:47

import sys

def get_ints():
    return map(int, sys.stdin.readline().strip().split())
def get_array():
    return list(get_ints())
def input():
    return sys.stdin.readline().strip()

a, b = get_ints()
print(a + b)