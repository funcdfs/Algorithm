/*
 * @lc app=leetcode.cn id=207 lang=golang
 *
 * [207] 课程表
 *
 * https://leetcode-cn.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (54.06%)
 * Likes:    1090
 * Dislikes: 0
 * Total Accepted:    165.1K
 * Total Submissions: 305.3K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。
 * 
 * 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi]
 * ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。
 * 
 * 
 * 例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
 * 
 * 
 * 请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：true
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要完成课程 0 。这是可能的。
 * 
 * 示例 2：
 * 
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0],[0,1]]
 * 输出：false
 * 解释：总共有 2 门课程。学习课程 1 之前，你需要先完成​课程 0 ；并且学习课程 0 之前，你还应先完成课程 1 。这是不可能的。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 0 
 * prerequisites[i].length == 2
 * 0 i, bi < numCourses
 * prerequisites[i] 中的所有课程对 互不相同
 * 
 * 
 */


package leetcode

/* --- 2022-01-20-15-01 --- */

// https://github.com/fengwei2002/Algorithm

// solution link: 
// 



// @lc code=start
func canFinish(n int, edges [][]int) bool {
	g := make([][]int, n)
	d := make([]int, n)

	for _, e := range edges {
		b, a := e[0], e[1]
		g[a] = append(g[a], b)
		d[b]++
	}

	q := make([]int, 0)
	for i := 0; i < n; i++ {
		if d[i] == 0 {
			q = append(q, i)
		}
	}

	cnt := 0
	for len(q) > 0 {
		t := q[0]
		q = q[1:]
		cnt++

		for _, i := range g[t] {
			d[i]--
			if d[i] == 0 {
				q = append(q, i)
			}
		}
	}

	return cnt == n
}
// @lc code=end

