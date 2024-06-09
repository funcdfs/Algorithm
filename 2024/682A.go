// created: 2024/6/6 11:57:08 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/682/problem/A

package main

import (
	"bufio"
	"fmt"
	"os"
)

// solve -------------------------------------------------------------

func solve() {

	n, m := input[int](), input[int]()

	// (x + y) % 5 == 0
	// pair cnt

	// 0.0 1.4 2.3 3.2 4.1
	a := make([]int, 5)
	b := make([]int, 5)

	for i := 1; i <= n; i++ {
		a[i%5] += 1
	}
	for i := 1; i <= m; i++ {
		b[i%5] += 1
	}
	ans := int64(0)
	for i := 0; i < 5; i++ {
		ans += int64(a[i]) * int64(b[(5-i)%5])
	}
	print(ans)
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
