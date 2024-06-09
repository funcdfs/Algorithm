// created: 2024/6/8 21:20:39 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1611/problem/C

package main

import (
	"bufio"
	"fmt"
	"os"
)

// region solve -------------------------------------------------------------

func solve(_case int) {

	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)
	n := input[int]()
	a := inputSlice[int](n)

}

// region solve -------------------------------------------------------------

// region main 
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
// endregion main
