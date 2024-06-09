// created: 2024/6/5 18:15:57 author:  https://github.com/funcdfs
// problem: https://atcoder.jp/contests/abc351/tasks/abc351_c

package main

import (
	"bufio"
	"fmt"
	"os"
)

// solve -------------------------------------------------------------

func solve() {

	n := input[int]()
	a := inputSlice[int](n)

	stk := make([]int, 0)
	for i := range a {
		stk = append(stk, a[i])
		if len(stk) >= 2 {
			for len(stk) >= 2 && stk[len(stk)-1] == stk[len(stk)-2] {
				x := stk[len(stk)-1]
				stk = stk[:len(stk)-2]
				stk = append(stk, x+1)
			}
		}
		// fmt.Fprintln(os.Stderr, a[i])
		// fmt.Fprintln(os.Stderr, stk)
	}

	print(len(stk))

}

// solve -------------------------------------------------------------

func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	// preProcess()
	solve()
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
