/*
 * @lc app=leetcode.cn id=400 lang=golang
 *
 * [400] 第 N 位数字
 */
package leetcode

import "strconv"

/* --- 2022-08-15-20-02 --- */
// https://github.com/fengwei2002/Algorithm
/*

1 \to 9 9
10 \to 99 90*2
100 \to 2700 900*3


第一步: 看数字 n 是几位数
	比如 n = 200: n - 9 = 191
				n - 180 = 11
				n < 2700 所以 n 是三位数
第二步:
	确定 n 是第几个 k 位数
		如果 n 是 1 到 k 的话 说明是第一个
		如果 n 是 k+1 到 2k 的话 说明是第二个
	第 n / k 上取整 个 k 位数
第三步:
	确定是这个数字的第几位
		n % k
			如果是 0 的话，就是第 k 位
			如果不是 0 的话， 就是第 n % k 位

*/
// @lc code=start
func findNthDigit(n int) int {
	k, t, s := 1, 9, 1 
	for n > t * k {
		n -= t * k 
		k++ 
		t *= 10 
		s *= 10 
	} 
	s += (n + k - 1) / k - 1 
	if (n % k) != 0 {
		n = n % k 
	} else {
		n = k
	} 

	return int(strconv.Itoa(s)[n - 1] - '0')
}

// @lc code=end
