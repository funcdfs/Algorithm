// link: https://codeforces.com/contest/734/problem/A A. Anton and Danik
// time: 2024/9/11 17:33:28 https://github.com/funcdfs

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

	cntA, cntD := 0, 0
	for i := 0; i < n; i++ {
		if s[i] == 'A' {
			cntA += 1
		} else if s[i] == 'D' {
			cntD += 1
		}
	}

	if cntA == cntD {
		println("Friendship")
	} else if cntA > cntD {
		println("Anton")
	} else if cntA < cntD {
		println("Danik")
	}

}

// ----------------------------- /* End of useful functions */ -------------------------------
