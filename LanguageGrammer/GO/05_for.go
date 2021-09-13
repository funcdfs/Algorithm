// go 中只有 for 一种循环结构

package main

import "fmt"

func main_ForGrammer() {
	// for 初始化语句; 条件语句; 修饰语句 {}
	for i := 0; i < 5; i++ {
		fmt.Printf("这是第 %d 次循环\n", i)
		for j := 0; j < 5; j++ {
			fmt.Printf("%d%d\n", i+1, j)
		}
	}
	for i, j := 0, 0; i < j; i, j = i+1, j-1 {
		// 在一个 for 循环中声明多个计时器， 独特的写法， 和 c++ 中的不一样
		// 变量，变量，操作符，变量变化的值
	}
}

// func main() {
// 	TriAngle()
// }

func TriAngle() {
	for i := 1; i <= 5; i++ {
		for j := 0; j < i; j++ {
			fmt.Printf("*")
		}
		fmt.Printf("\n")
	}
}

// for 循环结合 枚举（类似枚举） 和 Switch 一起使用

const (
	FIZZ     = 3
	BUZZ     = 5
	FIZZBUZZ = 15
)

func Fizz() {
	for i := 0; i <= 100; i++ {
		switch {
		case i%FIZZBUZZ == 0:
			fmt.Println("FizzBuzz")
		case i%FIZZ == 0:
			fmt.Println("Fizz")
		case i%BUZZ == 0:
			fmt.Println("Buzz")
		default:
			fmt.Println(i)
		}
	}
}

// -----------------------------------------------------------------
// 基于条件判断的迭代  while

func test0() {
	var i int = 5

	for i >= 0 {
		i = i - 1
		fmt.Printf("The variable i is now: %d\n", i)
	}
}

// ------------------------------------------------------------------
// 无限循环

// 条件语句是可以被省略的，如 i:=0; ; i++ 或 for { } 或 for ;; { }（;; 会在使用 gofmt 时被移除）：
// 这些循环的本质就是无限循环。最后一个形式也可以被改写为 for true { }，但一般情况下都会直接写 for { }。

// ------------------
// for-range 结构,
// 两个位置， 第一个位置的变量代表到达了第几轮，第二个变量代表第几轮对应的变量

var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}

func main_For_range() {
	for i, v := range pow {
		fmt.Printf("i = %d v = %d\n", i, v)
	}
}

// i= 0 v = 1
// i = 1 v = 2
// i = 2 v = 4
// i = 3 v = 8
// i = 4 v = 16
// i = 5 v = 32
