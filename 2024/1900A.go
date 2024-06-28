// link: https://codeforces.com/contest/1900/problem/A A. Cover in Water
// time: 2024/6/12 12:55:30 https://github.com/funcdfs

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
	constStr := input[string]()
	s := []byte(constStr)

	wall := make([]bool, n)
	for i := range s {
		if s[i] == '.' {
			wall[i] = false
		} else {
			wall[i] = true
		}
	}

	ans := 0

	for i := 0; i < len(wall); i++ {
		if wall[i] == false {
			idx := i
			for idx < len(wall) && wall[idx] == false {
				idx += 1
			}
			size := idx - i
			if size > 2 {
				print(2)
				return
			} else if size == 2 {
				ans += 2
			} else {
				ans += 1
			}
			i = idx
		}
	}

	print(ans)
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
