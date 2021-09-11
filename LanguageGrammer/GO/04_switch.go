package main

import "fmt"

func main() {
	fmt.Printf(Season(3))
}

func Season(month int) string {
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
