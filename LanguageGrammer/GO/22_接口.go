package main

import (
	"fmt"
)

type animal interface {
	run()
	eat()
}

// 声明接口

type cat struct {
	name string
	age  int64
}
type dog struct {
	name string
}

// 声明两个类型

func (c *cat) run() {
	fmt.Println(c.name, c.age, "正在跑步")
}

func (c *cat) eat() {
	fmt.Println(c.name, c.age, "正在吃饭")
}

// 将 cat 完善成一个接口实例

func (d *dog) run() {
	fmt.Println(d.name, "正在跑步")
}

func (d *dog) eat() {
	fmt.Println(d.name, "正在吃饭")
}

// 将 dog 完善为一个完整的接口实例

// 在一个函数中，使用接口作为参数，即可使用不同的接口实例函数

func test(t animal) {
	t.eat()
	t.run()
}

func main_接口() {
	c := cat{
		name: "Tom",
		age:  12,
	}
	d := dog{
		name: "haha",
	}
	test(&c)
	test(&d)
}

// https://jordanorelli.com/post/32665860244/how-to-use-interfaces-in-go
