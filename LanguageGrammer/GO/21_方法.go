package main

import "fmt"

type rect struct {
	width, height int
}

func (r *rect) area() int {
	return r.width * r.height
} // 这里的 area 是一个拥有 *rect 类型接收器(receiver)的方法。

func (r rect) perim() int {
	return 2*r.width + 2*r.height
} // 可以为值类型或者指针类型的接收者定义方法。 这是一个值类型接收者的例子。

func main_方法() {
	r := rect{width: 10, height: 5} // 使用结构体进行定义

	fmt.Println("area: ", r.area())
	fmt.Println("perim:", r.perim())

	rp := &r
	fmt.Println("area: ", rp.area())
	fmt.Println("perim:", rp.perim())
	// 调用方法时，Go 会自动处理值和指针之间的转换。
	// 想要避免在调用方法时产生一个拷贝，或者想让方法可以修改接受结构体的值， 你都可以使用指针来调用方法。
}
