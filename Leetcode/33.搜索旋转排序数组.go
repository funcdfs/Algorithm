/*
 * @lc app=leetcode.cn id=33 lang=golang
 *
 * [33] 搜索旋转排序数组
 */
package leetcode

/* --- 2022-04-07-15-56 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func search(nums []int, target int) int {
    l, r := 0, len(nums) - 1
    for l < r {
        mid := (l + r) >> 1 
        if nums[mid] <= nums[len(nums) - 1] {
            r = mid 
        } else {
            l = mid + 1 
        }
    } // 找到区间分隔点 
    
    if (target > nums[len(nums) - 1]) {
        r = l - 1
        l = 0 
    } else {
        r = len(nums) - 1 
    }

    for l < r {
        mid := (l + r + 1) >> 1 
        if nums[mid] <= target {
            l = mid
        } else {
            r = mid - 1 
        }
    }
    if nums[l] == target {
        return l
    }
    // l, r 这一段就是新的单调递增的区间，在单调递增的区间中在搜寻一次 target 
    
    return -1
}
// @lc code=end

