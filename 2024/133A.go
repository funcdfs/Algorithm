// link: https://codeforces.com/contest/133/problem/A A. HQ9+
// time: 2024/9/13 19:59:58 https://github.com/funcdfs

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
	hs := make(map[byte]struct{})
	hs['H'] = struct{}{}
	hs['Q'] = struct{}{}
	hs['9'] = struct{}{}

	for i := 0; i < len(s); i++ {
		if _, exist := hs[s[i]]; exist == true {
			println("YES")
			return
		}
	}

	println("NO")

}

// ----------------------------- /* End of useful functions */ -------------------------------
