/*
 * @lc app=leetcode.cn id=179 lang=golang
 *
 * [179] 最大数
 */
package leetcode

import (
	"sort"
	"strconv"
)

/* --- 2022-02-18-20-06 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
// https://leetcode-cn.com/problems/largest-number/solution/lc179-fengwei2002-by-konng0120-mo3n/

// @lc code=start
func largestNumber(nums []int) string {
	// 将一个数组组成一个可能出现的最大的数字并返回
	sort.Slice(nums, func(i, j int) bool {
		x := strconv.Itoa(nums[i])
		y := strconv.Itoa(nums[j])
		return x+y > y+x
	})
	ans := ""
	for _, v := range nums {
		ans += strconv.Itoa(v)
	}
	k := 0
	for k+1 < len(ans) && ans[k] == '0' {
		k++
	}
	return ans[k:]
}

// @lc code=end
