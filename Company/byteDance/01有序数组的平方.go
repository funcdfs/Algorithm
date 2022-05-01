package bytedance

import "sort"

// https://leetcode.cn/problems/squares-of-a-sorted-array/

func squareArrayBySort(a []int) []int {
	ans := make([]int, 0)
	for i := 0; i < len(a); i++ {
		ans = append(ans, a[i] * a[i])
	} 

	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	return ans
}


func squareArrayByPointer(a []int) []int {
	ans := make([]int, 0)
	for i := 0; i < len(a); i++ {
		ans = append(ans, a[i] * a[i])
	} 

	sort.Slice(ans, func(i, j int) bool {
		return ans[i] < ans[j]
	})

	return ans
}