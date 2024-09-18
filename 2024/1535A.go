// link: https://codeforces.com/contest/1535/problem/A A. Fair Playoff
// time: 2024/9/16 16:35:11 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
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

	a := inputSlice[int](4)
	maxA := slices.Max(a[0:2])
	maxB := slices.Max(a[2:len(a)])

	sort.Ints(a)
	if maxA > maxB {
		maxA, maxB = maxB, maxA
	}

	if maxB == a[len(a)-1] && maxA == a[len(a)-2] {
		println("YES")
	} else {
		println("NO")
	}

}

// ----------------------------- /* End of useful functions */ -------------------------------
