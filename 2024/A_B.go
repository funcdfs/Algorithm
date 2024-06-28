// created: 2024/6/10 18:47:33 author:  https://github.com/funcdfs
// problem: https://www.acwing.com/problem/content/1/

// #region import
package main

import (
	"bufio"
	"fmt"
	"os"
)

// #endregion import

// solve -------------------------------------------------------------

func solve() {
	a, b := input[int](), input[int]()
	print(a + b)
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
	solve()
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
