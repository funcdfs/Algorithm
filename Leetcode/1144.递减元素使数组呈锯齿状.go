/*
 * @lc app=leetcode.cn id=1144 lang=golang
 *
 * [1144] 递减元素使数组呈锯齿状
 */

package leetcode

/* --- 2022-03-09-18-14 --- */

// https://github.com/fengwei2002/Algorithm

// solution link: 
// 

// @lc code=start
func movesToMakeZigzag(nums []int) int {
	ans1 := 0
	ans2 := 0
	INT_MAX := 2<<31 - 1
	if len(nums) <= 2 {
		return 0
	}
	for i := 0; i < len(nums); i++ {
		l := INT_MAX 
		r := INT_MAX
		if i - 1 >= 0 {
			l = nums[i - 1]
		}
		if i + 1 < len(nums) {
			r = nums[i + 1]
		}
		if i & 1 == 0 {
			ans1 += max(0, nums[i] - mini(l, r) + 1)
		} else {
			ans2 += max(0, nums[i] - mini(l, r) + 1)
		}
	}
	return mini(ans1, ans2)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func mini(a, b int) int {
	if a < b {
		return a
	}
	return b
}
// @lc code=end

