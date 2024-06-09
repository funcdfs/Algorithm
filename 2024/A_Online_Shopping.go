// created: 2024/6/5 18:26:47 author:  https://github.com/funcdfs
// problem: https://atcoder.jp/contests/abc332/tasks/abc332_a

package main

import (
	"bufio"
	"fmt"
	"os"
)

// solve -------------------------------------------------------------

func solve() {

	N, S, K := input[int](), input[int](), input[int]()

	P := make([]int, N)
	Q := make([]int, N)
	for i := 0; i < N; i++ {
		P[i], Q[i] = input[int](), input[int]()
	}
	ans := int64(0)
	for i := range P {
		this := P[i] * Q[i]
		ans += int64(this)
	}
	if ans < int64(S) {
		ans += int64(K)
	}
	print(ans)
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
