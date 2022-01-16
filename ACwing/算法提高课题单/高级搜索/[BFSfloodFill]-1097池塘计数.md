## 1097 池塘计数

农夫约翰有一片  N∗M  的矩形土地。

最近，由于降雨的原因，部分土地被水淹没了。

现在用一个字符矩阵来表示他的土地。

每个单元格内，如果包含雨水，则用 ”W” 表示，如果不含雨水，则用 ”.” 表示。

现在，约翰想知道他的土地中形成了多少片池塘。

每组相连的积水单元格集合可以看作是一片池塘。

每个单元格视为与其上、下、左、右、左上、右上、左下、右下八个邻近单元格相连。

请你输出共有多少片池塘，即矩阵中共有多少片相连的”W”块。

## 输入格式

第一行包含两个整数  N  和  M 。

接下来  N  行，每行包含  M  个字符，字符为 ”W” 或 ”.”，用以表示矩形土地的积水状况，字符之间没有空格。

## 输出格式

输出一个整数，表示池塘数目。

## 数据范围

`1 ≤ N, M ≤ 1000`

## 输入样例：

``` cpp
10 12
W........WW.
.WWW.....WWW
....WW...WW.
.........WW.
.........W..
..W......W..
.W.W.....WW.
W.W.W.....W.
.W.W......W.
..W.......W.
```

## 输出样例：

``` cpp
3
```

## 思路：

bfs一圈一圈的扩充 floodfill 算法，可以在线性时间复杂度内找到某个点所在的连通块

使用宽搜不会出现爆栈的风险（DFS 会，因为层数越多栈的层级越多）

一般情况下可以用宽搜实现都用宽搜实现


``` cpp 
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 1010, M = N * N;

int n, m;
char g[N][N];

bool st[N][N];

void bfs(int sx, int sy) { 
    queue<PII> q;
    q.push({ sx, sy });
    st[sx][sy] = true;

    while (q.size()) {
        auto t = q.front();
        q.pop();


        // 八连通去除中间块
        int tx = t.first, ty = t.second;
        for (int i = tx - 1; i <= tx + 1; i++) {
            for (int j = ty - 1; j <= ty + 1; j++) {
                if (i == tx && j == ty) continue;
                if (i < 0 || i >= n || j < 0 || j >= m) continue;
                if (g[i][j] == '.' || st[i][j]) continue;

                q.push({ i, j });
                st[i][j] = true;
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", g[i]);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == 'W' && !st[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
```