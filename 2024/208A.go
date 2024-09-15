// link: https://codeforces.com/contest/208/problem/A A. Dubstep
// time: 2024/9/15 12:17:54 https://github.com/funcdfs

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
	
	s := input[[]byte]()
	ans := make([]byte, 0)
	ansWithoutSpace := make([]byte, 0)
	s = append(s, []byte("WUBWUB")...)

	for i := 0; i < len(s) - 3; i++ {
		if string(s[i:i+3]) == "WUB" {
			ans = append(ans, []byte(" ")...)
			i += 2
		} else {
			ans = append(ans, s[i])
		}
	}

	for i := 0; i < len(ans); i++ {
		if ans[i] == ' ' {
			ansWithoutSpace = append(ansWithoutSpace, []byte(" ")...)
			idx := i 
			for idx < len(ans) && ans[idx] == ' ' {
				idx += 1
			}
			i = idx-1
		} else {
			ansWithoutSpace = append(ansWithoutSpace, ans[i])
		}
	}

	println(string(ansWithoutSpace))

}

// ----------------------------- /* End of useful functions */ -------------------------------
