// link: https://codeforces.com/contest/158/problem/A A. Next Round
// time: 2024/9/8 15:16:27 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
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
func print[T any](arr ...T)   { _print_config(" ", " ", arr) }
func println[T any](arr ...T) { _print_config(" ", "\n", arr...) }

// #endregion main

// ----------------------------- /* Start of useful functions */ -----------------------------

func solve() {

	n, k := input[int](), input[int]()
	a := inputSlice[int](n)

	

	cnt := 0
	l, r := 0, len(a)-1
	for l < r {
		mid := (l + r) >> 1
		if a[mid] > k {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if l == 0 {
		for i := 0; i < n; i++ {
			if a[i] == k {
				cnt += 1
			} else {
				break
			}
		}
	} else {
		cnt = l + 1
	}
 
	println(cnt)
}

// ----------------------------- /* End of useful functions */ -------------------------------
