// created: 2024/6/5 19:04:17 author:  https://github.com/funcdfs
// problem: https://atcoder.jp/contests/abc253/tasks/abc253_a

package main

import (
	"bufio"
	"fmt"
	"os"
)

// solve -------------------------------------------------------------

func solve() {

	A, B, C := input[int](), input[int](), input[int]()

	if B >= A && B <= C {
		print("Yes")
		return
	} else if B >= C && B <= A {
		print("Yes")
		return
	}
	print("No")
	return
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
