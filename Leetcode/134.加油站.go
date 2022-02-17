/*
 * @lc app=leetcode.cn id=134 lang=golang
 *
 * [134] 加油站
 */
package leetcode

/* --- 2022-02-15-10-32 --- */

// https://github.com/fengwei2002/Algorithm

// solution link: 
// https://leetcode-cn.com/problems/gas-station/solution/lc134-fengwei2002-by-konng0120-nvua/

// @lc code=start
func canCompleteCircuit(gas []int, cost []int) int {
	n := len(gas)
	for i := 0; i < n; i++ {
		leftGas := 0
		j := 0
		for ; j < n; j++ {
			k := (i + j) % n
			leftGas += gas[k] - cost[k]
			if leftGas < 0 {
				break
			}
		}

		if leftGas >= 0 {
			return i
		} else {
			i = i + j;
		}
	}

	return -1
}
// @lc code=end

