/*

anInt, _ = strconv.Atoi(origStr)
将一个字符串转换为一个整数

如果 origStr 不能被转换为整数，anInt 的值会变成 0 而 _ 无视了错误，程序会继续运行。

这样做是非常不好的：程序应该在最接近的位置检查所有相关的错误，至少需要暗示用户有错误发生并对函数进行返回，甚至中断程序。

我们在第二个版本中对代码进行了改进：

*/

package main

import (
	"fmt"
	"strconv"
)

func FuncError() {
	var orig string = "ABC"
	// var orig2 string = "1"

	var newS string

	fmt.Printf("int 的大小是  %d\n", strconv.IntSize)
	// anInt, err = strconv.Atoi(origStr)
	an, err := strconv.Atoi(orig) // 将 ABC 转换为整数

	if err != nil {
		fmt.Printf("orig 字符串 %s 不是一个整数 - exiting with error\n", orig)
		// return
	}
	fmt.Printf("The integer is %d\n", an)
	an = an + 5
	newS = strconv.Itoa(an)
	fmt.Printf("The new string is: %s\n", newS)
}


/*

习惯用法 ：

if err != nil {
	fmt.Printf("Program stopping with error %v", err)
	os.Exit(1)
}

此处的退出代码 1 可以使用外部脚本获取到）

有时候，你会发现这种习惯用法被连续重复地使用在某段代码中。

当没有错误发生时，代码继续运行就是唯一要做的事情，所以 if 语句块后面不需要使用 else 分支。


示例 2：我们尝试通过 os.Open 方法打开一个名为 name 的只读文件：

f, err := os.Open(name)
if err != nil {
	return err
}
doSomething(f) // 当没有错误发生时，文件对象被传入到某个函数中
doSomething



*/