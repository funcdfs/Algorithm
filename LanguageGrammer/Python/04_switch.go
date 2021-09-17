package main

// func main() {
// 	var ans string = Season(3)
// 	fmt.Printf("%s", ans)
// }

// 写一个 Season 函数，要求接受一个代表月份的数字，然后返回所代表月份所在季节的名称（不用考虑月份的日期）。

func main_Season(month int) string {
	switch month {
	case 12, 1, 2:
		return "Winter"
	case 3, 4, 5:
		return "Spring"
	case 6, 7, 8:
		return "Summer"
	case 9, 10, 11:
		return "Autumn"
	}
	return "Season unknown"
}

/*

优雅的对函数的运行结果进行判断

switch result := calculate(); {
case result < 0:
	...
case result > 0:
	...
default:
	// 0
}

*/
