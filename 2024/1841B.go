// link: https://codeforces.com/contest/1841/problem/B B. Keep it Beautiful
// time: 2024/6/12 12:28:16 https://github.com/funcdfs

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

	x := make([]int, 0, n)
	x = append(x, a[0])
	print(1)

	ok := false

	for i := 1; i < len(a); i++ {
		if ok == true {
			if a[i] <= x[0] && a[i] >= x[len(x)-1] {
				x = append(x, a[i])
				print(1)
			} else {
				print(0)
			}
		} else if ok == false {
			if a[i] >= x[len(x)-1] {
				x = append(x, a[i])
				print(1)
			} else if a[i] <= x[len(x)-1] && a[i] <= x[0] {
				x = append(x, a[i])
				print(1)
				ok = true
			} else {
				print(0)
			}
		}
	}
	print("\n")
	return
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
			// fmt.Fprintln(_out)
		} else {
			fmt.Fprint(_out, "")
		}
	}
}

// #endregion fastIO
