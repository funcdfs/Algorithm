// link: https://codeforces.com/contest/263/problem/A A. Beautiful Matrix
// time: 2024/9/10 13:22:11 https://github.com/funcdfs

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

	x, y := 0, 0

	grid := make([][]int, 5)
	for i := 0; i < 5; i++ {
		grid[i] = make([]int, 5)
		for j := 0; j < 5; j++ {
			grid[i][j] = input[int]()
			if grid[i][j] == 1 {
				x, y = i, j
			}
		}
	}

	cnt := Abs(x-2) + Abs(y-2)
	println(cnt)
}

func Abs[T int | int64 | float32 | float64](x T) T {
	if x < T(0) {
		return -x
	}
	return x
}
// ----------------------------- /* End of useful functions */ -------------------------------
