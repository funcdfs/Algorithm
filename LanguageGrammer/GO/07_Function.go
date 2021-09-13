package main

import "fmt"

var num int = 10
var numx2, numx3 int

// 比较 命名返回值 和 不命名返回值 的写法 ，函数的返回值直接在 函数头部和参数一起声明
// 尽量使用命名返回值：会使代码更清晰、更简短，同时更加容易读懂。

func main_Function() {
	numx2, numx3 = getX2AndX3(num)
	PrintValues()
	numx2, numx3 = getX2AndX3_2(num)
	PrintValues()
}

func PrintValues() {
	fmt.Printf("num = %d, 2x num = %d, 3x num = %d\n", num, numx2, numx3)
}

func getX2AndX3(input int) (int, int) {
	return 2 * input, 3 * input
}

func getX2AndX3_2(input int) (x2 int, x3 int) {
	x2 = 2 * input
	x3 = 3 * input
	return x2, x3
	// return
}

// 举例：使用两种函数返回值写法，计算加减乘除

// mult_returnval.go

func SumProductDiff(i, j int) (int, int, int) {
	return i + j, i * j, i - j
}

func SumProductDiffN(i, j int) (s int, p int, d int) {
	s, p, d = i+j, i*j, i-j
	return
}

func main_mult_returnval() {
	sum, prod, diff := SumProductDiff(3, 4)
	fmt.Println("Sum:", sum, "| Product:", prod, "| Diff:", diff)
	sum, prod, diff = SumProductDiffN(3, 4)
	fmt.Println("Sum:", sum, "| Product:", prod, "| Diff:", diff)
}

// Sum: 7 | Product: 12 | Diff: -1
// Sum: 7 | Product: 12 | Diff: -1

// -----------------------------------------
// 使用 函数修改 外部变量

// this function changes reply:
func Multiply(a, b int, reply *int) {
	*reply = a * b
}

func main_Change() {
	n := 0
	reply := &n
	Multiply(10, 5, reply)
	fmt.Println("Multiply:", *reply) // Multiply: 50
}
