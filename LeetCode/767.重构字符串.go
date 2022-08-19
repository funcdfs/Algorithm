/*
 * @lc app=leetcode.cn id=767 lang=golang
 *
 * [767] 重构字符串
 */
package leetcode

/* --- 2022-08-16-15-13 --- */
// https://github.com/fengwei2002/Algorithm
/*



*/
// @lc code=start
func reorganizeString(s string) string {
	hash := make(map[byte]int, 0) 
	for i := 0; i < len(s); i++ {
		hash[s[i]]++ 
	} 
	
	flag := true

	for _, v := range hash {
		if v > len(s) / 2 {
			return false 
		}
	} 
	

}
// @lc code=end

