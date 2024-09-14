// link: https://codeforces.com/contest/705/problem/A A. Hulk
// time: 2024/9/11 18:07:54 https://github.com/funcdfs

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
	str1 := "I hate"
	str2 := "I love"
	str3 := "that"
	str4 := "it"

	even := false

	for i := 0; i < n; i++ {
		if i == n-1 {
			if even {
				print(str2, " ")
			} else {
				print(str1, " ")
			}
			print(str4)
			return
		}
		if even {
			print(str2, " ")
		} else {
			print(str1, " ")
		}
		print(str3, " ")
		even = !even
	}

}

// ----------------------------- /* End of useful functions */ -------------------------------
