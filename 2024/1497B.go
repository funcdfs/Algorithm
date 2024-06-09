// created: 2024/6/9 13:57:17 author:  https://github.com/funcdfs 
// problem: https://codeforces.com/contest/1497/problem/B

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
	
	n, m := input[int](), input[int]()
	a := inputSlice[int](n) 
	
	

}


func preProcess() {

}

// solve -------------------------------------------------------------

// #region main
func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	preProcess()
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
