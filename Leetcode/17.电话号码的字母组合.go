/*
 * @lc app=leetcode.cn id=17 lang=golang
 *
 * [17] 电话号码的字母组合
 */
package leetcode

/* --- 2022-04-06-23-03 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start

var hash map[int]string = map[int]string{
	0: "",
	1: "",
	2: "abc",
	3: "def",
	4: "ghi",
	5: "jkl",
	6: "mno",
	7: "pqrs",
	8: "tuv",
	9: "wxyz",
}

func letterCombinations(digits string) []string {
	// 输入一个数字串 输出所有可能的字符串结果
	ans := make([]string, 0)
	path := make([]byte, 0)
	if len(digits) == 0 {
		return ans
	}
	n := len(digits)
	var dfs func(int, int)
	// index 代表当前的下标，cnt 代表当前已经放入的元素个数
	
	dfs = func(index int, cnt int) {
		if cnt == n {
			pathCopy := make([]byte, n)
			copy(pathCopy, path)
			ans = append(ans, string(pathCopy))
			return
		}
		for i := index; i < n; i++ {
			x := int(digits[i]) - int('0')
			for j := 0; j < len(hash[x]); j++ {
				path = append(path, hash[x][j])
				cnt++
				dfs(i + 1, cnt)
				cnt--
				path = path[:len(path)-1]
			}
		}
	}
	dfs(0, 0)
	return ans
}

// @lc code=end
