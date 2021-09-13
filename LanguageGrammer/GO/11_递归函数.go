package main

import "fmt"

func main_fibonacci() {
	result := 0
	for i := 0; i <= 10; i++ {
		result = fibonacci(i)
		fmt.Printf("fibonacci(%d) is: %d\n", i, result)
	}
}

func fibonacci(n int) (res int) {
	if n <= 1 {
		res = 1
	} else {
		res = fibonacci(n-1) + fibonacci(n-2)
	}
	return
}

// -------------------------------------------------------

func print1To10(n int) {
	// 使用递归函数从 10 打印到  1
	if n == 1 {
		fmt.Printf("%d", n)
		return
	}
	fmt.Printf("%d ", n)
	n--
	print1To10(n)
}

// func main() {
// 	print1To10(10)
// }

// 实现一个输出前 30 个整数的阶乘的程序。--------------------

var sum int = 1
func factorial(n int) {
	if n == 1 {
		fmt.Printf("%d", sum)
		return
	}
	sum *= n
	n--
	factorial(n)
}

func main() {
	factorial(4)
}



