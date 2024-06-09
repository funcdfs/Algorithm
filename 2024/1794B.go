// created: 2024/6/6 12:20:22 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1794/problem/B

package main

import (
	"bufio"
	"fmt"
	"os"
)

// solve -------------------------------------------------------------

func solve(_case int) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)
	n := input[int]()
	a := inputSlice[int](n)

	// max operation cnt is 2 * n

	for i := range a {
		if a[i] == 1 {
			a[i] += 1
		}
		if i == 0 {
			continue
		}
		if a[i]%a[i-1] == 0 {
			a[i] += 1
		}
	}
	print(a...)
}

// solve -------------------------------------------------------------

func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	// preProcess()
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
}

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
