// link: https://codeforces.com/contest/1861/problem/B B. Two Binary Strings
// time: 2024/6/16 10:56:40 https://github.com/funcdfs

// #region import
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

// #endregion import

// solve -------------------------------------------------------------

func solve(_case int) {
	// log.Println("# CASE: ", _case)

	constStr := input[string]()
	s1 := []byte(constStr)
	constStr = input[string]()
	s2 := []byte(constStr)

	// 区间替换，端点处必须相等，然后整个段内都变成相同的。
	// 问两个字符串是否可以变成相同的，都是 0 开头，1 结尾。

	/// 000000011111111, find the same position "01"
	check := func() bool {
		for i := range s1 {
			if i == 0 {
				continue
			}
			if s1[i] == '1' && s1[i-1] == '0' && s2[i] == '1' && s2[i-1] == '0' {
				return true
			}
		}
		return false
	}
	if check() == true {
		print("YES")
	} else {
		print("NO")
	}

}

// solve -------------------------------------------------------------

// #region main
func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	log.SetFlags(log.Lshortfile)
	defer _out.Flush()
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
}

// #endregion main

// #region io
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
			fmt.Fprint(_out, "\n")
		} else {
			fmt.Fprint(_out, " ")
		}
	}
}
func println() {
	fmt.Fprint(_out, "\n")
}
func printx[T any](x ...T) {
	for i := range x {
		fmt.Fprint(_out, x[i], " ")
	}
}

// #endregion io
