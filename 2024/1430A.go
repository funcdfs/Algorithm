// created: 2024/6/5 17:13:46 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1430/problem/A

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

	// // 3x + 5y + 7z = n
	for z := 0; z*7 <= n; z++ {
		for y := 0; z*7+y*5 <= n; y++ {
			diff := n - 5*y - 7*z
			if diff%3 == 0 {
				print(diff/3, y, z)
				// fmt.Fprintln(os.Stderr, diff + 5 * y + 7 * z, n)
				return
			}
		}
	}
	print(-1)
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
