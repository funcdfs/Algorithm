// link: https://atcoder.jp/contests/abc366/tasks/abc366_a A - Election 2
// time: 2024/9/10 13:01:44 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
)

var _in, _out = new(bufio.Reader), new(bufio.Writer)

func _print_config[T any](sep, end string, arr ...T) {
	for idx := range arr {
		fmt.Fprint(_out, arr[idx])
		if idx == len(arr)-1 {
			fmt.Fprint(_out, end)
		} else {
			fmt.Fprint(_out, sep)
		}
	}
}
func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	solve()
}
func input[T any]() T { var value T; fmt.Fscan(_in, &value); return value }
func inputSlice[T any](size int) []T {
	data := make([]T, size)
	for idx := 0; idx < size; idx++ {
		data[idx] = input[T]()
	}
	return data
}
func print[T any](arr ...T)   { _print_config(" ", " ", arr...) }
func println[T any](arr ...T) { _print_config(" ", "\n", arr...) }

// #endregion main

// ----------------------------- /* Start of useful functions */ -----------------------------

func solve() {

	total, a, b := input[int](), input[int](), input[int]()

	diff := total - (a + b)
	if diff+Min(a, b) > Max(a, b) {
		println("No")
	} else {
		println("Yes")
	}
}

func Max[T int | int64 | float32 | float64](x ...T) T {
	maxVal := x[0]
	for _, v := range x {
		if v > maxVal {
			maxVal = v
		}
	}
	return maxVal
}

func Min[T int | int64 | float32 | float64](x ...T) T {
	minVal := x[0]
	for _, v := range x {
		if v < minVal {
			minVal = v
		}
	}
	return minVal
}

// ----------------------------- /* End of useful functions */ -------------------------------
