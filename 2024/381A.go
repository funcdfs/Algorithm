// link: https://codeforces.com/contest/381/problem/A A. Sereja and Dima
// time: 2024/9/15 19:18:00 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
)

var _in, _out = new(bufio.Reader), new(bufio.Writer)

func _github_funcdfs[T any](sep, end string, arr ...T) {
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
func print[T any](arr ...T)   { _github_funcdfs("", "", arr...) }
func println[T any](arr ...T) { _github_funcdfs(" ", "\n", arr...) }

// #endregion main

// ----------------------------- /* Start of useful functions */ -----------------------------

func solve() {

	n := input[int]()
	a := inputSlice[int](n)

	sum := 0
	for i := range a {
		sum += a[i]
	}
	fir, sec := 0, 0
	ok := true
	for i := 0; i < n; i++ {
		maxVal := -1
		if a[0] >= a[len(a)-1] {
			maxVal = a[0]
			a = a[1:len(a)]
		} else {
			maxVal = a[len(a)-1]
			a = a[0 : len(a)-1]
		}
		if ok {
			fir += maxVal
		} else {
			sec += maxVal
		}
		ok = !ok
	}
	println(fir, sec)

}

// ----------------------------- /* End of useful functions */ -------------------------------
