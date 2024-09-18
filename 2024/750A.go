// link: https://codeforces.com/contest/750/problem/A A. New Year and Hurry
// time: 2024/9/18 14:51:38 https://github.com/funcdfs

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

	n, k := input[int](), input[int]()

	oneLoopSum := n * (5 + n*5) / 2
	println(n, oneLoopSum)
	cnt := 0
	if k > oneLoopSum {
		cnt += (k / oneLoopSum) * n
		k = k % oneLoopSum
	}

	l, r := 0, n
	for l < r {
		mid := (l + r) >> 1
		if k >= mid*5 {
			l = mid
		} else {
			r = mid - 1
		}
	}

	cnt += l

	println(cnt)

}

// ----------------------------- /* End of useful functions */ -------------------------------
