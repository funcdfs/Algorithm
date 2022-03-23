FGD小朋友特别喜欢爬山，在爬山的时候他就在研究山峰和山谷。  

为了能够对旅程有一个安排，他想知道山峰和山谷的数量。  

给定一个地图，为FGD想要旅行的区域，地图被分为 `n×n` 的网格，每个格子 `(i,j)` 的高度 `w(i,j)`是给定的。  

若两个格子有公共顶点，那么它们就是相邻的格子，如与 `(i,j) `相邻的格子有   

- `(i-1, j-1) (i-1, j) (i-1, j+1) `

- `(i, j-1) (i, j+1) `

- `(i+1, j-1) (i+1, j) (i+1, j+1)`

我们定义一个格子的集合 S 为山峰（山谷）当且仅当：  

1. S 的所有格子都有相同的高度。  
2. S 的所有格子都连通。  
3. 对于 s 属于 S，与 s 相邻的 s′ 不属于 S，都有 `ws>ws′`（山峰），或者 `ws<ws′`（山谷）。  
4. 如果周围不存在相邻区域，则同时将其视为山峰和山谷。  

你的任务是，对于给定的地图，求出山峰和山谷的数量，如果所有格子都有相同的高度，那么整个地图即是山峰，又是山谷。  

第一行包含一个正整数 n，表示地图的大小。  

接下来一个 n×n 的矩阵，表示地图上每个格子的高度 w。  

#### 输出格式   

共一行，包含两个整数，表示山峰和山谷的数量。  

#### 数据范围  

`1≤ n ≤ 1000`  
`0 ≤ w ≤ 109`  

#### 输入样例1：  

```
5
8 8 8 7 7
7 7 8 8 7
7 7 7 7 7
7 8 8 7 8
7 8 8 8 8
```

#### 输出样例1：   

```
2 1
```

#### 输入样例2：   

```
5
5 7 8 3 1
5 5 7 6 6
6 6 6 2 8
5 7 2 5 8
7 1 0 1 7
```

#### 输出样例2：  

```
3 3
```

#### 样例解释  

样例1：  

![1.png](https://cdn.acwing.com/media/article/image/2019/10/16/19_0250799aef-1.png)

样例2：  

![2.png](https://cdn.acwing.com/media/article/image/2019/10/16/19_08db5e60ef-2.png)

``` cpp
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1010;
int g[N][N];
bool st[N][N];
int n;

void bfs(int x, int y, bool& has_higher, bool& has_lower) {
    queue<pair<int, int>> q;
    q.push({x, y});
    st[x][y] = true;

    while (q.size()) {
        auto t = q.front();
        q.pop();
        int tx = t.first, ty = t.second;
        for (int i = tx - 1; i <= tx + 1; i++) {
            for (int j = ty - 1; j <= ty + 1; j++) {
                if (i == tx && j == ty) continue;
                if (i < 0 || i >= n || j < 0 || j >= n) continue;
                if (g[i][j] == g[tx][ty] && st[i][j] == false) {
                    q.push({i, j});
                    st[i][j] = true;
                } else if (g[i][j] != g[tx][ty]) {
                	if (g[i][j] > g[tx][ty]) {
                		has_higher = true;
                	} else {
                		has_lower = true;
                	}
                }
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
        }
    }

    int peak = 0, valley = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!st[i][j]) {
                bool has_higher = false, has_lower = false;
                bfs(i, j, has_higher, has_lower);
                if (!has_higher) peak++;
                if (!has_lower) valley++;
            }
        }
    }

    cout << peak << ' ' << valley << endl;
}
```

在做 floodfill 算法的同时统计他和他周围连通块之间的关系

注意边界值的判断，什么情况应该放入队列，什么情况应该去更新具体的变量

