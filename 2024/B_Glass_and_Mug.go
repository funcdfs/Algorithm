// created: 2024/6/5 18:45:37 author:  https://github.com/funcdfs 
// problem: https://atcoder.jp/contests/abc332/tasks/abc332_b

package main

import (
	"bufio"
	"fmt"
	"os"
)

// solve -------------------------------------------------------------

func solve() {
	
	K, G, M := input[int](), input[int](), input[int]()
	

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
