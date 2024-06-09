// created: 2024/6/5 18:00:33 author:  https://github.com/funcdfs
// problem: https://www.luogu.com.cn/problem/AT_abc351_a

package main

import (
	"bufio"
	"fmt"
	"os"
)

// solve -------------------------------------------------------------

func solve() {

	arr := inputSlice[int](17)
	A := arr[0:9]
	B := arr[9:]
	sumA := Accumulate(A...)
	sumB := Accumulate(B...)
	// sumA < sumB + x
	// sumA - sumB < x
	x := (sumA - sumB) + 1
	print(x)
}

func Accumulate[T int | int64 | float32 | float64 | string](args ...T) T {
	var res T
	for _, v := range args {
		res += v
	}
	return res
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
