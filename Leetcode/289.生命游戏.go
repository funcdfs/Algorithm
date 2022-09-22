/*
 * @lc app=leetcode.cn id=289 lang=golang
 *
 * [289] 生命游戏
 */
package leetcode

/* --- 2022-09-21-23-35 --- */
// https://github.com/fengwei2002/Algorithm
/*



*/
// @lc code=start
func gameOfLife(board [][]int)  {
	if len(board) == 0 || len(board[0]) == 0 {
		return 
	} 
	n := len(board)
	m := len(board[0]) 

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			live := 0
			for x := max(0, i - 1); x <= min(i + 1, n - 1); x++ {
				for y := max(0, j - 1); y <= min(j + 1, m - 1); y++ {
					if x == i && y == j {
						continue 
					} 
					if (board[x][y] & 1) == 1 {
						live++
					}
				}
			} 

			cur := board[i][j] & 1 
			next := -1
			if cur == 1 {
				if live < 2 || live > 3 {
					next = 0
				} else {
					next = 1
				}
			} else {
				if live == 3 {
					next = 1 
				} else {
					next = 0 
				}
			}
			board[i][j] |= (next << 1)
		}
	}

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			board[i][j] >>= 1
		}
	}
}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
// @lc code=end

