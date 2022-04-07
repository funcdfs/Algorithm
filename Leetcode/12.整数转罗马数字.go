/*
 * @lc app=leetcode.cn id=12 lang=golang
 *
 * [12] 整数转罗马数字
 */
package leetcode

/* --- 2022-04-06-20-01 --- */
// https://github.com/fengwei2002/Algorithm

// @lc code=start

type mapping struct {
	Value  int
	Symbol string
}

var hash []mapping = []mapping{
	{1000, "M"},
	{900, "CM"},
	{500, "D"},
	{400, "CD"},
	{100, "C"},
	{90, "XC"},
	{50, "L"},
	{40, "XL"},
	{10, "X"},
	{9, "IX"},
	{5, "V"},
	{4, "IV"},
	{1, "I"},
}

func intToRoman(num int) string {
	roman := make([]byte, 0)
	for _ /*index*/, v := range hash {
		for num >= v.Value {
			num -= v.Value
			roman = append(roman, []byte(v.Symbol)...)
		}
	}
	return string(roman)
}

// @lc code=end
