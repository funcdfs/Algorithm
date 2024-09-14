// link: https://codeforces.com/contest/266/problem/A A. Stones on the Table
// time: 2024/9/11 10:31:50 https://github.com/funcdfs

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
	s := input[[]byte]()
	tot := 0

	for i, j := 0, 0; i < n; i = j {
		for j = i + 1; j < n && s[j] == s[i]; j++ {
			// tot += 1
		}
		// println(string(s[i:j])), all same pattern
		// tot += len(s[i:j]) - 1
		tot += j - i - 1
	}

	

	// last := s[0]
	// for i := 1; i < n; i++ {
	// 	if s[i] == last {
	// 		tot += 1
	// 	} else {
	// 		last = s[i]
	// 	}
	// }


	println(tot)
}

// ----------------------------- /* End of useful functions */ -------------------------------
