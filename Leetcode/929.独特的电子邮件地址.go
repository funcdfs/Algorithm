/*
 * @lc app=leetcode.cn id=929 lang=golang
 *
 * [929] 独特的电子邮件地址
 */
package leetcode

import "strings"

/* --- 2022-06-07-16-27 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start
func numUniqueEmails(emails []string) int {
	hash := make(map[string]bool, 0) 

	for _, email := range emails {
		atIndex := strings.IndexRune(email, '@')
		local := strings.SplitN(email[:atIndex], "+", 2)[0]
		local = strings.ReplaceAll(local, ".", "") 
		hash[local+email[atIndex:]] = true 
	}
	return len(hash)
}
// @lc code=end

