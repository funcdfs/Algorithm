package main

import "fmt"

/*
map 是一种特殊的数据结构：一种元素对（pair）的无序集合，
pair 的一个元素是 key，对应的另一个元素是 value，所以这个结构也称为关联数组或字典。
这是一种快速寻找值的理想结构：给定 key，对应的 value 可以迅速定位。

map 这种数据结构在其他编程语言中也称为字典（Python）、hash 和 HashTable 等。


*/

func main_map基础语法() {
	var value int
	var isPresent bool // 两个变量用于接收 map 测试的结果

	map1 := make(map[string]int)

	map1["ShangHai"] = 55
	map1["BeiJing"] = 20
	map1["Washington"] = 25

	value, isPresent = map1["BeiJing"]
	// _, ok := map1[key1] // 如果key1存在则ok == true，否则 ok 的值为 false

	if isPresent {
		fmt.Printf("BeiJing 在 map1 中的值是 %d\n", value)
	} else {
		fmt.Printf("map1 中不存在 BeiJing ")
	}

	value, isPresent = map1["Paris"]
	fmt.Printf("Is \"Paris\" in map1 ?: %t\n", isPresent)
	fmt.Printf("Value is: %d\n", value)

	// delete an item: 在 map1 中删除 key1 直接 delete(map1, key1) 就可以。

	delete(map1, "Washington")
	value, isPresent = map1["Washington"]

	if isPresent {
		fmt.Printf("The value of \"Washington\" in map1 is: %d\n", value)
	} else {
		fmt.Println("map1 does not contain Washington")
	}
}

func main_map_forRange() {

	/* 第一个返回值 key 是 map 中的 key 值，第二个返回值则是该 key 对应的 value 值；

	这两个都是仅 for 循环内部可见的局部变量。其中第一个返回值key值是一个可选元素。如果你只关心值，可以这么使用：

	for _, value := range map1 {
	 	...
	}
	相比于其他的 for range map 拥有特殊的 kew value 值

	*/
	map1 := make(map[int]float32)
	map1[1] = 1.0
	map1[2] = 2.0
	map1[3] = 3.0
	map1[4] = 4.0
	for key, value := range map1 {
		fmt.Printf("key is: %d - value is: %f\n", key, value)
		// 注意 map 不是按照 key 的顺序排列的，也不是按照 value 的序排列的。
	}
	capitals := map[string]string{"France": "Paris", "Italy": "Rome", "Japan": "Tokyo"}
	for key := range capitals {
		fmt.Println("Map item: Capital of", key, "is", capitals[key])
	}

}
