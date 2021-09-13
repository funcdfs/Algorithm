package main

import "fmt"

// 下面这个函数，返回一个函数，但是返回的这一个函数不需要具体的名字

func intSeq() func() int {
	i := 0
	return func() int {
		i++
		return i
	}
}

func main_闭包() {
	// intSeq 函数调用一次就加一
	nextInt := intSeq()

	fmt.Println(nextInt()) // 1
	fmt.Println(nextInt()) // 2
	fmt.Println(nextInt()) // 3

	newInts := intSeq()
	fmt.Println(newInts()) // 1
}

/*

匿名函数同样被称之为闭包（函数式语言的术语）：
它们被允许调用定义在其它环境下的变量。

*/