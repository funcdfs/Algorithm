[题目链接](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/)  
[题解链接](https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/jz12-fengwei2002-dfs-pian-yi-liang-shu-z-7wzt/)

https://github.com/fengwei2002/algorithm

### 剑指 Offer 12. 矩阵中的路径

给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

![20211018143554-2021-10-18-14-35-57](https://raw.githubusercontent.com/fengwei2002/Pictures_02/master/images/20211018143554-2021-10-18-14-35-57.png)

### 思路

对于每一个位置，对它的四个方向进行搜索

从第二个位置开始只从三个方向向后继续搜索，每次搜索这个方向的时候去除这个树枝已经搜索过的点

利用 矩阵偏移量数组 和 DFS， 很经典的一个 DFS 搜索题目

### C++

``` cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int u, int x, int y) {
        if (board[x][y] != word[u]) return false;
        if (u == word.size() - 1) return true;

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        
        char t = board[x][y];
        board[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.') continue;
            if (dfs(board, word, u + 1, a, b)) return true;
        }
        board[x][y] = t;

        return false;
    }
};
```

### GO

注意 golang 标准的格式 加一减一不用空格隔开

``` go  
func exist(board [][]byte, word string) bool {
	for i := 0; i < len(board); i++ {
		for j := 0; j < len(board[0]); j++ {
			if dfs(board, word, 0, i, j) == true {
				return true
			}
		}
	}
	return false
}

func dfs(board [][]byte, word string, u int, x int, y int) bool {
	if board[x][y] != word[u] {
		return false
	}
	if u == len(word)-1 {
		return true
	}

	dx := [4]int{-1, 0, 1, 0}
	dy := [4]int{0, 1, 0, -1}

	t := board[x][y]
	board[x][y] = '.'
	for i := 0; i < 4; i++ {
		a := x + dx[i]
		b := y + dy[i]
		if a < 0 || a >= len(board) || b < 0 || b >= len(board[0]) || board[a][b] == '.' {
			continue
		}
		if dfs(board, word, u+1, a, b) == true {
			return true
		}
	}

	board[x][y] = t

	return false
}
```