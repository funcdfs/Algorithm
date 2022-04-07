/*
 * @lc app=leetcode.cn id=6 lang=golang
 *
 * [6] Z 字形变换
 */
package leetcode

/* --- 2022-01-07-21-08 --- */

// https://github.com/fengwei2002/Algorithm
// solution link:
// https://leetcode-cn.com/problems/zigzag-conversion/solution/lc6-fengwei2002-zhao-gui-lu-by-fengwei20-p6nc/

// @lc code=start
func convert(s string, n int) string {
	ans := make([]byte, 0, len(s))
	if n == 1 {
		return s
	}

	for i := 0; i < n; i++ {
		if i == 0 || i == (n-1) {
			for j := i; j < len(s); j += 2*n - 2 {
				ans = append(ans, s[j])
			}
		} else {
			for j, k := i, 2*n-2-i; j < len(s) || k < len(s); j, k = j+2*n-2, k+2*n-2 {
				if j < len(s) {
					ans = append(ans, s[j])
				}
				if k < len(s) {
					ans = append(ans, s[k])
				}
			}
		}
	}
	return string(ans)
}

// @lc code=end
// 第一行是一个公差为 2n - 2 的等差数列
// 第二行：
//      变为两个等差数列进行表示，在柱子上的和不在柱子上的
//      每一个单独的等差数列，公差都是 2n - 2
//      只是他们的首项不同
//      在柱子上的首项为 i, 不在柱子上的首项为 0 + 2n - 2 - i
// 最后一行和第一行一样，只是一个公差为 2n - 2 的等差数列
