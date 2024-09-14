// link: https://codeforces.com/contest/520/problem/A A. Pangram
// time: 2024/9/11 18:15:04 https://github.com/funcdfs

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

	tb := make([]int, int('z')-int('a')+1)
	for i := 0; i < n; i++ {
		if s[i] >= 'A' && s[i] <= 'Z' {
			s[i] = byte(int(s[i]) - (int('A') - int('a')))
		}
		tb[int(s[i])-int('a')] = 1
	}
	cnt := 0
	for i := 0; i < len(tb); i++ {
		if tb[i] == 1 {
			cnt += 1
		}
	}
	if cnt == len(tb) {
		println("YES")
	} else {
		println("NO")
	}
}

// ----------------------------- /* End of useful functions */ -------------------------------
