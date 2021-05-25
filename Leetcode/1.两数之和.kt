/*
 * @lc app=leetcode.cn id=1 lang=kotlin
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        var indexFirst = 0
        var indexSecond = 1
        for (a in nums.indices) {
            for (b in nums.indices) {
                if (a != b && nums[a] + nums[b] == target) {
                    indexFirst = a
                    indexSecond = b
                    break
                }
            }
        }
        if (indexFirst > indexSecond) {
            val temp = indexFirst
            indexFirst = indexSecond
            indexSecond = temp
        }
        return intArrayOf(indexFirst, indexSecond)
        //当一个值只在返回的时候使用的话使用内联函数的写法
    }
}
// @lc code=end

