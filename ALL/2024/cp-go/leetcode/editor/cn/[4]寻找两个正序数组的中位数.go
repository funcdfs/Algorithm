// 4 寻找两个正序数组的中位数
// 2024-05-16 12:33:34
package main

// leetcode submit region begin(Prohibit modification and deletion)
func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	ans := 0.0
	tot := len(nums1) + len(nums2)
	if tot%2 == 0 {
		left := find(nums1, 0, nums2, 0, tot/2)
		right := find(nums1, 0, nums2, 0, tot/2+1)
		ans = (left + right) / 2
	}
	return ans
}

func find(nums1 []int, i int, nums2 []int, j, k int) float64 {
	if len(nums1)-i > len(nums2)-j {
		return find(nums2, j, nums1, i, k)
	}
	if k == 1 {
		if len(nums1) == i {
			return float64(nums2[j])
		} else {
			return float64(min(nums1[i], nums2[j]))
		}
	}

	if len(nums1) == i {
		return float64(nums2[j+k-1])
	}
	newi := min(len(nums1), i + k /2)
	newj := j + k / 2;

	if nums1[newi - 1] < nums2[newj - 1] {
		return find(nums1, newi, nums2, j, k - (newi - i));
	}
	return find(nums1, i, nums2, newj, k - (newj - j));
}

//leetcode submit region end(Prohibit modification and deletion)
