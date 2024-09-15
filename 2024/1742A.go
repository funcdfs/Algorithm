// link: https://codeforces.com/contest/1742/problem/A A. Sum
// time: 2024/9/15 19:15:32 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
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
func solve(_case int) {

	a := inputSlice[int](3)
	sort.Ints(a)

	if a[2] == a[0]+a[1] {
		println("YES")
	} else {
		println("NO")
	}

}

// ----------------------------- /* End of useful functions */ -------------------------------
