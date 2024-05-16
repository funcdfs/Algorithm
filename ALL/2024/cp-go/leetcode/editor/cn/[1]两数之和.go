// 1 两数之和
// 2024-05-16 11:37:08
package main
//leetcode submit region begin(Prohibit modification and deletion)
func twoSum(nums []int, target int) []int {
	hs := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		if val, ok := hs[target-nums[i]]; ok {
			return []int{val, i}
		}
		hs[nums[i]] = i
	}
	return nil
}
//leetcode submit region end(Prohibit modification and deletion)
