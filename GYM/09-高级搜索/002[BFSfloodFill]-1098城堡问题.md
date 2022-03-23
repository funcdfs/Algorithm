``` cpp
    1   2   3   4   5   6   7  
   #############################
 1 #   |   #   |   #   |   |   #
   #####---#####---#---#####---#
 2 #   #   |   #   #   #   #   #
   #---#####---#####---#####---#
 3 #   |   |   #   #   #   #   #
   #---#########---#####---#---#
 4 #   #   |   |   |   |   #   #
   #############################
           （图 1)
   #  = Wall   
   |  = No wall
   -  = No wall

   方向：上北下南左西右东。
```

![20220108114138-2022-01-08-11-41-39](https://raw.githubusercontent.com/fengwei2002/Pictures_02/master/images/20220108114138-2022-01-08-11-41-39.png)

图 1 是一个城堡的地形图。

请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。

城堡被分割成  m∗n 个方格区域，每个方格区域可以有 0~4 面墙。

注意：墙体厚度忽略不计。

**输入格式**
第一行包含两个整数  m  和  n ，分别表示城堡南北方向的长度和东西方向的长度。

接下来  m  行，每行包含  n  个整数，每个整数都表示平面图对应位置的方块的墙的特征。

每个方块中墙的特征由数字  P  来描述，我们用 1 表示西（左）墙，2 表示北（上）墙，4 表示东（右）墙，8 表示南（下）墙， P  为该方块包含墙的数字之和。

例如，如果一个方块的  P  为 3，则 3 = 1 + 2，该方块包含西墙和北墙。

城堡的内墙被计算两次，方块 (1,1) 的南墙同时也是方块 (2,1) 的北墙。

输入的数据保证城堡至少有两个房间。

**输出格式**
共两行，第一行输出房间总数，第二行输出最大房间的面积（方块数）。

**数据范围**

`1 ≤ m, n ≤ 50 `,
`0 ≤ P ≤ 15`

**输入样例：**

``` cpp
4 7 
11 6 11 6 3 10 6 
7 9 6 13 5 15 5 
1 10 12 7 13 7 5 
13 11 10 8 10 12 13 
```

**输出样例：**

``` cpp
5
9
```

**输入样例**：

``` cpp
5 7
3 14 11 2 2 2 6
5 3 10 4 5 1 4
13 13 7 5 5 9 4
15 3 12 9 12 11 12
11 8 10 10 10 14 15
```

**输出样例**：

``` cpp
5
20
```



## 思路

看某个方向有没有墙，就是看某一位的二进制表示是不是 1

相比于池塘计数多了一个统计数量的过程


``` cpp 
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 55;
int n, m;
int g[N][N];
bool st[N][N];

int bfs(int x, int y) {
    queue<pair<int, int>> q;
	int area = 0;
    q.push({x, y});
    area++;
    st[x][y] = true;

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};
    
    while (q.size()) {
        auto t = q.front();
        q.pop();
        
        
        int tx = t.first, ty = t.second;
        for (int i = 0; i < 4; i++) {
            int a = dx[i] + tx;
            int b = dy[i] + ty;
            
            if (a < 0 || a >= n || b < 0 || b >= m) continue;
            if (st[a][b] == true) continue;
            if (g[tx][ty] >> i & 1) continue;
            
            q.push({a, b});
            area++;
            st[a][b] = true;
        }
    }
    
    return area;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    
    int cnt = 0, area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!st[i][j]) {
                area = max(area, bfs(i, j));
                cnt++;
            }
        }
    }
    cout << cnt << '\n' << area << endl;
    return 0;
}
```

注意 `area++` 的时刻，如果在放入的时候加，那么就全部在放入元素的时候加，如果在 pop 的时候++，那么就全部在 pop 的时候进行统计

