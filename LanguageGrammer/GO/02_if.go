package main

import "fmt"

func IfGrammer() {
	// if condition {    // 无括号
	//	   do something
	// }
	fmt.Print("ifGrammer")

	// 在 if 条件中声明一个比较变量 进行使用
	var max int = 11
	fmt.Scanf("%d", max)
	if val := 10; max < val {
		fmt.Print("max < 10")
	}

}

func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func IsGreater(x, y int) bool {
	// if x > y {
	// 	return true
	// }
	// return false   should be:
	return x > y
}
