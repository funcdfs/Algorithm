finalx, finaly, horsex, horsey = map(int, input().split(' '))

f = [[0 for i in range(finaly + 1)] for i in range(finalx + 1)]

dx = [-1, -2, -2, -1, 1, 2, 2, 1]
dy = [-2, -1, 1, 2, 2, 1, -1, -2]

for i in range(0, finalx + 1):
    f[i][0] = 1
for j in range(0, finaly + 1):
    f[0][j] = 1

f[horsex][horsey] = -1
for i in range(0, 8):
    a = dx[i] + horsex
    b = dy[i] + horsey
    if a >= 0 and b >= 0:
        f[a][b] = -1

for i in range(finalx + 1):
    for j in range(finaly + 1):
        print(f[i][j], end=' ')
    print()

for i in range(1, finalx + 1):
    for j in range(1, finaly + 1):
        if f[i][j] == -1:
            continue
        f[i][j] = f[i][j - 1] + f[i - 1][j]
        if f[i][j - 1] == -1:
            f[i][j] += 1
        if f[i - 1][j] == -1:
            f[i][j] += 1

print(f[finalx][finaly])
