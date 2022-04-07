/*
 * @lc app=leetcode.cn id=22 lang=golang
 *
 * [22] 括号生成
 */
package leetcode

/* --- 2022-04-07-10-32 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start

func generateParenthesis(n int) []string {
    ans := make([]string, 0) 
    path := make([]byte, 0)
    
    var dfs func(int, int) 
    dfs = func(leftCount int, rightCount int) {
        if leftCount == n && rightCount == n {
            pathCopy := make([]byte, len(path))
            copy(pathCopy, path)
            ans = append(ans, string(pathCopy))
            return 
        }
        if leftCount < n {
            path = append(path, '(')
            dfs(leftCount + 1, rightCount)
            path = path[:len(path) - 1]
        }
        if leftCount > rightCount && rightCount < n {
            path = append(path, ')')
            dfs(leftCount, rightCount + 1)
            path = path[:len(path) - 1]
        }
    }
    dfs(0, 0)
    return ans
}
// @lc code=end

