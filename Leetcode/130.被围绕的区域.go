/*
 * @lc app=leetcode.cn id=130 lang=golang
 * [130] 被围绕的区域
 */

package leetcode

/* --- 2021-11-19-15-28 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode.cn/problems/surrounded-regions/solution/lc130-fengwei2002-ni-xiang-si-kao-by-kyc-6s1a/

// @lc code=start

var n, m int

func solve(board [][]byte) {
	// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

	// 与其去寻找哪些 O 被包围，不如去寻找哪些 O 没有被包围
	n = len(board)
	if n == 0 {
		return
	}
	m = len(board[0])

	for i := 0; i < n; i++ {
		if board[i][0] == 'O' {
			dfs(board, i, 0)
		}
		if board[i][m-1] == 'O' {
			dfs(board, i, m-1)
		}
	}

	for i := 0; i < m; i++ {
		if board[0][i] == 'O' {
			dfs(board, 0, i)
		}
		if board[n-1][i] == 'O' {
			dfs(board, n-1, i)
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if board[i][j] == '#' {
				board[i][j] = 'O'
			} else if board[i][j] == 'O' {
				board[i][j] = 'X'
			}
		}
	}
}

func dfs(board [][]byte, x int, y int) {
	dx := [4]int{-1, 0, 1, 0}
	dy := [4]int{0, 1, 0, -1}

	board[x][y] = '#'

	for i := 0; i < 4; i++ {
		a, b := x+dx[i], y+dy[i]

		if a >= 0 && a < n && b >= 0 && b < m && board[a][b] == 'O' {
			dfs(board, a, b)
		}
	}
}

// @lc code=end
