[题目链接](https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/)  
[题解链接]()

https://github.com/fengwei2002/algorithm

### 剑指 Offer 13. 机器人的运动范围

地上有一个 m 行 n 列的方格，从坐标 `[0,0]` 到坐标 `[m-1,n-1]` 。一个机器人从坐标 `[0, 0]` 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于 k 的格子。例如，当 k 为 18 时，机器人能够进入方格 `[35, 37]` ，因为 `3+5+3+7=18`。但它不能进入方格 `[35, 38]`，因为 `3+5+3+8=19`。请问该机器人能够到达多少个格子？

### 思路

相当于在一条存在障碍物的地图中找到一条最长的路径

![20211020162133-2021-10-20-16-21-34](https://raw.githubusercontent.com/fengwei2002/Pictures_02/master/images/20211020162133-2021-10-20-16-21-34.png)
![20211020162208-2021-10-20-16-22-09](https://raw.githubusercontent.com/fengwei2002/Pictures_02/master/images/20211020162208-2021-10-20-16-22-09.png)

每个格子里的值为行坐标和列坐标的数位之和，蓝色方格代表非障碍方格，即其值小于等于当前的限制条件 k。我们可以发现随着限制条件 k 的增大，所在的蓝色方格区域内新加入的非障碍方格都可以由上方或左方的格子移动一步得到。而其他不连通的蓝色方格区域会随着 k 的增大而连通，且连通的时候也是由上方或左方的格子移动一步得到，因此我们可以将我们的搜索方向缩减为向右或向下

![20211020162447-2021-10-20-16-24-48](https://raw.githubusercontent.com/fengwei2002/Pictures_02/master/images/20211020162447-2021-10-20-16-24-48.png)

![20211020162510-2021-10-20-16-25-11](https://raw.githubusercontent.com/fengwei2002/Pictures_02/master/images/20211020162510-2021-10-20-16-25-11.png)
### C++

``` cpp
class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;

    int movingCount(int _m, int _n, int k) {
        m = _m, n = _n;
        visited = vector<vector<bool>>(m, vector<bool>(n, false));
        return dfs(0, 0, k);
    }

    // dfs 是求出来坐标 i j 开始向下和向右能够到达的格子的数量
    int dfs(int i, int j, int k) {
        if (sum(i, j) > k || i >= m || j >= n || visited[i][j]) {
            return 0;
            // 可能出现数值下标越界异常，所以可以将 visited 放在判断越界的后面
        }

        visited[i][j] = true;

        // 只需要向下或者向右执行， 走一步多一格路径
        return 1 + dfs(i + 1, j, k) + dfs(i, j + 1, k);
    }

    int sum(int i, int j) {
        // sum 函数求出 i 和 j 两个数字按照位数相加的结果
        int sum = 0;
        while (i != 0) {
            sum += i % 10;
            i /= 10;
        } 
        while (j != 0) {
            sum += j % 10;
            j /= 10;
        }

        return sum;
    }
};
```

TODO ### GO 剑指 offer 13


``` go
var n1, m1, k1 int
var visited [][]bool

func movingCount(m int, n int, k int) int {
	m1 = m
	n1 = n
	k1 = k
	visited = make([][]bool, m)
	for i := 0; i < len(visited); i++ {
		visited[i] = make([]bool, n)
	}
	return dfs(0, 0, 0, 0)
}

func dfs(i int, j int, si int, sj int) int {
	if i >= m1 || j >= n1 || si+sj > k1 || visited[i][j] {
		return 0
	}
	visited[i][j] = true

	sj1 := sj + 1
	si1 := si + 1
	if (j+1)%10 == 0 {
		sj1 = sj - 8
	}
	if (i+1)%10 == 0 {
		si1 = si - 8
	}

	return 1 + dfs(i, j+1, si, sj1) + dfs(i+1, j, si1, sj)
}
```