/*

从字符串生成字节切片

https://github.com/unknwon/the-way-to-go_ZH_CN/blob/master/eBook/07.5.md
https://github.com/unknwon/the-way-to-go_ZH_CN/blob/master/eBook/07.6.md
*/

package main

import "fmt"

func main_切片的应用() {
	slFrom := []int{1, 2, 3}
	slTo := make([]int, 10)
	// 开辟了两个切片

	n := copy(slTo, slFrom) // 使用 copy 函数
	fmt.Println(slTo)
	fmt.Printf("Copied %d elements\n", n) // n == 3

	sl3 := []int{1, 2, 3}
	sl3 = append(sl3, 4, 5, 6)
	fmt.Println(sl3)
}
