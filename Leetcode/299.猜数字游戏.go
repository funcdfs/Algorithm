/*
 * @lc app=leetcode.cn id=299 lang=golang
 *
 * [299] 猜数字游戏
 */
package leetcode

import "fmt"

/* --- 2022-09-22-10-17 --- */
// https://github.com/fengwei2002/Algorithm
// @lc code=start
func getHint(secret string, guess string) string {
	hs := make(map[rune]int, 0) 
	for _, c := range secret {
		hs[c]++
	}

	tot := 0
	for _, c := range guess {
		if v, ok := hs[c]; ok == true && v > 0 {
			hs[c]--
			tot++
		}
	}

	bulls := 0
	for i := 0; i < len(secret); i++ {
		if secret[i] == guess[i] {
			bulls++
		}
	}

	return fmt.Sprintf("%dA%dB", bulls, tot-bulls)
}
// @lc code=end

