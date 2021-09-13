/*

数组是具有相同 唯一类型 的一组已编号且长度固定的数据项序列
数组长度必须是一个常量表达式，并且必须是一个非负整数。数组长度也是数组类型的一部分

所以[5]int和[10]int是属于不同类型的。

数组长度最大为 2Gb

*/

// 声明格式： var identifier [len]type

package main

import "fmt"

func main_for循环与数组() {
	/*
		对于数组来说，遍历数组，当然是使用 for 循环来实现
		通过 for 初始化数组项
		通过 for 打印数组元素
		通过 for 依次处理元素
	*/
	var arr1 [5]int

	for i := 0; i < len(arr1); i++ { // 这里使用 go 语言的内置函数
		arr1[i] = i * 2
	}

	for i := 0; i < len(arr1); i++ {
		fmt.Printf("Array at index %d is %d\n", i, arr1[i])
	}
	for i := range arr1 {
		fmt.Printf("%d", arr1[i])
	}
	for _, v := range arr1 {
		fmt.Printf("%d", v)
	}

	/*
		习惯用法(IDIOM)
		for i:=0; i < len(arr1); i++｛
			arr1[i] = ...
		}
		for range 实现遍历 for range 的第二个参数可以直接不写

		for i, _ := range arr1 {
			...
		}

	*/
}

// Go 语言中的数组是一种 值类型（不像 C/C++ 中是指向首元素的指针），所以可以通过 new() 来创建： var arr1 = new([5]int)。
// 那么这种方式和 var arr2 [5]int 的区别是什么呢？arr1 的类型是 *[5]int，而 arr2的类型是 [5]int。

// TODO func main_不同的数组声明方式() { }

// 数组常量初始化

func main_数组常量初始化() {
	// var arrAge = [5]int{18, 20, 15, 22, 16}
	// var arrLazy = [...]int{5, 6, 7, 8, 22}
	// var arrLazy = []int{5, 6, 7, 8, 22}	//注：初始化得到的实际上是切片slice
	var arrKeyValue = [5]string{3: "Chris", 4: "Ron"}
	// var arrKeyValue = []string{3: "Chris", 4: "Ron"}	//注：初始化得到的实际上是切片slice

	for i := 0; i < len(arrKeyValue); i++ {
		fmt.Printf("Person at %d is %s\n", i, arrKeyValue[i])
	}
	var arrAge = [5]int{18, 20, 15, 22, 16}
	// 未手动声明的数组元素值都是，0

	// key: value 语法
	var arrKeyValue = [5]string{3: "Chris", 4: "Ron"}
	// 只有索引 3 和 4 被赋予实际的值，其他元素都被设置为空的字符串

}

func fp(a *[3]int) { fmt.Println(a) }

func main_pointer_array_go() {
	for i := 0; i < 3; i++ {
		fp(&[3]int{i, i * i, i * i * i})
	}
}

// ----------------------------- 多维数组
const (
	WIDTH  = 1920
	HEIGHT = 1080
)

type pixel int // pixel: 像素

var screen [WIDTH][HEIGHT]pixel

func main_多维数组() {
	for y := 0; y < HEIGHT; y++ { // 遍历同 C++ 两个 for 循环即可
		for x := 0; x < WIDTH; x++ {
			screen[x][y] = 1
		}
	}
}

// -------------------------------- 将数组传递给函数

func main_将数组传递给函数() {
	array := [3]float64{7.0, 8.5, 9.1}
	x := Sum(&array) // 请注意运算符的显式地址
	// 传递一个指向数组的指针
	fmt.Printf("数组的总和是:%f", x)
}

func Sum(a *[3]float64) (sum float64) {
	for _, v := range a {
		sum += v
	}
	return sum
}
