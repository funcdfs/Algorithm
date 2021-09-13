package main

import "fmt"

func main_defer() {
	function1()
}

func function1() {
	fmt.Printf("In function1 at the top\n")
	defer function2()
	fmt.Printf("In function1 at the bottom!\n")
}

func function2() {
	fmt.Printf("Function2: Deferred until the end of the calling function!")
}

// 使用 defer 之后， top  bottom end 不使用 defer  top end bottom

func a() {
	i := 0
	defer fmt.Println(i)
	i++
	return
}

// func main() {
// 	a()
// }

// 使用 defer 的语句同样可以接受参数，下面这个例子就会在执行 defer 语句时打印 0：
// 虽然上面这个函数，return 之前执行了 i++ 但是 defer 还是在 i++ 之前， 所以就是输出 0

func f() {
	for i := 0; i < 5; i++ {
		defer fmt.Printf("%d ", i)
	}
}

// func main() {
// 	f() // 43210  
// }
// 当有多个 defer 行为被注册时，它们会以逆序执行（类似栈，即后进先出）：


