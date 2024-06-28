// link: https://codeforces.com/contest/1858/problem/C C. Yet Another Permutation Problem
// time: 2024/6/12 21:39:06 https://github.com/funcdfs

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
	st := make([]bool, n+1)

	// 构造 gcd(a[i], a[i+1]) 的种类 最多的一个排列
	// [1] [2 4 8 16] [3 6 12 24] 5 7 ...
	a := make([]int, 0, n)
	a = append(a, 1)
	st[1] = true

	for base := 2; base <= n; base += 1 {
		if st[base] == true {
			continue
		}
		x := base
		a = append(a, x)
		for x*2 <= n && st[x*2] == false {
			x = x * 2
			a = append(a, x)
			st[x] = true
		}
	}

	print(a...)
}

// solve -------------------------------------------------------------

// #region main

func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	// preProcess()
	testCaseCnt := input[int]()
	for i := 1; i <= testCaseCnt; i++ {
		solve(i)
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

// #endregion fastIO
