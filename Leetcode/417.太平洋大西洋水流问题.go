/*
 * @lc app=leetcode.cn id=417 lang=golang
 *
 * [417] 太平洋大西洋水流问题
 */
package leetcode
/* --- 2022-06-07-16-39 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func pacificAtlantic(heights [][]int) [][]int {
	if len(heights) == 0 || len(heights[0]) == 0{
		return [][]int{}
	}
	n, m := len(heights), len(heights[0])
	st := make([][]int, n) 
	for i := 0; i < n; i++ {
		st[i] = make([]int, m)
	}
	dx := [...]int{0, 1, 0, -1}
	dy := [...]int{1, 0, -1, 0}

    var dfs func(int, int, int) 
	
	dfs = func(x, y, status int) {
		if (st[x][y] & status) > 0 {
			return
		} 
		st[x][y] |= status
		for i := 0; i < 4; i++ {
			a, b := x + dx[i], y + dy[i]
			if a >= 0 && a < n && b >= 0 && b < m && heights[a][b] >= heights[x][y] {
				dfs(a, b, status)
			}
		}
	}

	for i := 0; i < n; i++ {
		dfs(i, 0, 1)
	}
	for i := 0; i < m; i++ {
		dfs(0, i, 1)
	}
	for i := 0; i < n; i++ {
		dfs(i, m - 1, 2)
	}	 
	for i := 0; i < m; i++ {
		dfs(n - 1, i, 2)
	}
	ans := make([][]int, 0)

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if st[i][j] == 3 {
				ans = append(ans, []int{i, j})
			}
		}
	}

	return ans
}
// @lc code=end