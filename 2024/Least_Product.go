// LUOGU_RID: 161929880
// link: https://www.luogu.com.cn/problem/CF1917A Least Product
// time: 2024/6/12 11:40:28 https://github.com/funcdfs

// #region import
package main

import (
	"bufio"
	"fmt"
	"os"
)

// #endregion import

// solve -------------------------------------------------------------

func solve(_case int) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)
	n := input[int]()
	a := inputSlice[int](n)

	// a[i] < 0 => a[i] 替换为 [ai, 0] 的任意整数，否则将 a[i] 替换为 [0, ai] 中的任意整数
	// 最小化操作次数，使得总乘积最小。

	pow := int64(1)
	for i := range a {
		pow *= int64(a[i])
	}
	if pow <= 0 {
		print(0)
		return
	} else {
		print(1)
		print(1, 0)
		return
	}
	return
}


// solve -------------------------------------------------------------

// #region main
func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
}

// #endregion main

// #region fastIO
var _in *bufio.Reader
var _out *bufio.Writer

func input[T any]() T {
	var value T
	fmt.Fscan(_in, &value)
	return value
}
func inputSlice[T any](length int) []T {
	data := make([]T, length)
	for i := 0; i < length; i++ {
		data[i] = input[T]()
	}
	return data
}
func print[T any](x ...T) {
	for i := range x {
		fmt.Fprint(_out, x[i])
		if i == len(x)-1 {
			fmt.Fprintln(_out)
		} else {
			fmt.Fprint(_out, " ")
		}
	}
}

// #endregion fastIO
