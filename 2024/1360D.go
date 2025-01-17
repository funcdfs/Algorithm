// link: https://codeforces.com/contest/1360/problem/D D. Buying Shovels
// time: 2024/9/29 19:58:29 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"math"
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

	n, k := input[int](), input[int]()

	ans := math.MaxInt32
	for i := 1; i*i <= n; i++ {
		if n%i == 0 {
			if i <= k {
				ans = min(ans, n/i)
			}
			if n/i <= k {
				ans = min(ans, i)
			}
		}
	}
	println(ans)

}

// ----------------------------- /* End of useful functions */ -------------------------------
