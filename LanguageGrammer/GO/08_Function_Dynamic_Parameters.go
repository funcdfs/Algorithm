//  如果函数的最后一个参数是采用 ...type 的形式，那么这个函数就可以处理一个变长的参数，这个长度可以为 0，这样的函数称为变参函数。

//  func myFunc(a, b, arg ...int) {}

/*

func Greeting(prefix string, who ...string)
Greeting("hello:", "Joe", "Anna", "Eileen")

在 Greeting 函数中，变量 who 的值为 []string{"Joe", "Anna", "Eileen"}。
如果参数被存储在一个 slice 类型的变量 slice 中，则可以通过 slice... 的形式来传递参数，调用变参函数

*/

package main

import "fmt"

func main() {
	x := min(1, 3, 2, 0)
	fmt.Printf("The minimum is: %d\n", x)
	x2 := []int{7, 9, 3, 5, 1}
	x = min(x2...)
	fmt.Printf("The minimum in the slice is: %d", x)
}

func min(s ...int) int { // 接收任意数量的 int 作为参数
	if len(s) == 0 {
		return 0
	}
	min := s[0]

	for _, v := range s {
		if v < min {
			min = v
		}
	}
	return min
}

// 如果你有一个含有多个值的 slice，想把它们作为参数使用， 你需要这样调用 func(slice...)。

