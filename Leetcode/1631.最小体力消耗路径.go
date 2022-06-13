/*
 * @lc app=leetcode.cn id=1631 lang=golang
 *
 * [1631] 最小体力消耗路径
 */
package leetcode

/* --- 2022-06-07-15-19 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func minimumEffortPath(heights [][]int) int {
	var check func(int) bool
	var dx = [...]int{0, 1, 0, -1}
	var dy = [...]int{1, 0, -1, 0}
	n, m := len(heights), len(heights[0])

	check = func(limit int) bool {
		que := make([][]int, 0)
		que = append(que, []int{0, 0})
		st := make([][]bool, n)
		for i := 0; i < n; i++ {
			st[i] = make([]bool, m)
			for j := 0; j < m; j++ {
				st[i][j] = false
			}
		}
		st[0][0] = true

		for len(que) > 0 {
			tx, ty := que[0][0], que[0][1]
			que = que[1:]
			if tx == n-1 && ty == m-1 {
				return true
			}
			for i := 0; i < 4; i++ {
				a, b := tx+dx[i], ty+dy[i]
				if a < 0 || a >= n || b < 0 || b >= m {
					continue
				}
				if st[a][b] == true {
					continue
				}
				if abs(heights[a][b]-heights[tx][ty]) > limit {
					continue
				}
				que = append(que, []int{a, b})
				st[a][b] = true
			}
		}

		return false
	}

	l, r := 0, int(1e6)
	for l < r {
		mid := (l + r) >> 1
		if check(mid) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

// @lc code=end
