/*
 * @lc app=leetcode.cn id=205 lang=golang
 *
 * [205] 同构字符串
 */
package leetcode

/* --- 2022-01-20-17-31 --- */

// https://github.com/fengwei2002/Algorithm

// solution link:
// https://leetcode.cn/problems/isomorphic-strings/solution/lc205-fengwei2002-by-kycu-rs78/

// @lc code=start
func isIsomorphic(s string, t string) bool {
	byteS := []byte(s)
	byteT := []byte(t)

	hashS := make(map[byte]byte)
	hashT := make(map[byte]byte)

	for i := 0; i < len(byteS); i++ {
		a := byteS[i]
		b := byteT[i]
		if v, ok := hashS[a]; ok == true && v != b {
			return false
		}
		hashS[a] = b
		if v, ok := hashT[b]; ok == true && v != a {
			return false
		}
		hashT[b] = a
	}

	return true
}

// @lc code=end
