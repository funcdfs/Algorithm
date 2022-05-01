/*
 * @lc app=leetcode.cn id=210 lang=golang
 *
 * [210] 课程表 II
 *
 * https://leetcode.cn/problems/course-schedule-ii/description/
 *
 * algorithms
 * Medium (54.79%)
 * Likes:    551
 * Dislikes: 0
 * Total Accepted:    103.8K
 * Total Submissions: 189.4K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中
 * prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。
 * 
 * 
 * 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
 * 
 * 
 * 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：numCourses = 2, prerequisites = [[1,0]]
 * 输出：[0,1]
 * 解释：总共有 2 门课程。要学习课程 1，你需要先完成课程 0。因此，正确的课程顺序为 [0,1] 。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
 * 输出：[0,2,1,3]
 * 解释：总共有 4 门课程。要学习课程 3，你应该先完成课程 1 和课程 2。并且课程 1 和课程 2 都应该排在课程 0 之后。
 * 因此，一个正确的课程顺序是 [0,1,2,3] 。另一个正确的排序是 [0,2,1,3] 。
 * 
 * 示例 3：
 * 
 * 
 * 输入：numCourses = 1, prerequisites = []
 * 输出：[0]
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= numCourses <= 2000
 * 0 <= prerequisites.length <= numCourses * (numCourses - 1)
 * prerequisites[i].length == 2
 * 0 <= ai, bi < numCourses
 * ai != bi
 * 所有[ai, bi] 互不相同
 * 
 * 
 */
package leetcode

/* --- 2022-01-21-13-25 --- */

// https://github.com/fengwei2002/Algorithm

// solution link: 
// https://leetcode.cn/problems/course-schedule-ii/solution/lc210-fengwei2002-by-kycu-8hya/

// @lc code=start
func findOrder(n int, edges [][]int) []int {
	g := make([][]int, n) 
	d := make([]int, n)
	for _, e := range edges {
		a, b := e[1], e[0]
		g[a] = append(g[a], b)
		d[b]++
	}

	ans := make([]int, 0)
	q := make([]int, 0)

	for i := 0; i < n; i++ {
		if d[i] == 0 {
			q = append(q, i)
		}
	}


	for len(q) > 0 {
		t := q[0]
		q = q[1:]
		ans = append(ans, t)

		for _, i := range g[t] {
			d[i]--
			if d[i] == 0 {
				q = append(q, i)
			}
		}
	}

	if len(ans) < n {
		ans = make([]int, 0)
	}
	return ans
}
// @lc code=end

