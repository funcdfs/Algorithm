package main

import "fmt"

func main_IfGrammer() {
	// if condition {    // 圆括号不是必须的，但是方括号是必须的
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

// Go 没有三目运算符， 即使是基本的条件判断，依然需要使用完整的 if 语句。

