// link: https://codeforces.com/contest/59/problem/A A. Word
// time: 2024/9/11 17:08:37 https://github.com/funcdfs

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

	cntLower, cntUpper := 0, 0
	for i := 0; i < len(s); i++ {
		if s[i] >= 'a' && s[i] <= 'z' {
			cntLower += 1
		} else if s[i] >= 'A' && s[i] <= 'Z' {
			cntUpper += 1
		}
	}

	if cntLower >= cntUpper {
		for i := 0; i < len(s); i++ {
			if s[i] >= 'A' && s[i] <= 'Z' {
				s[i] = byte(int(s[i]) - (int('A') - int('a')))
			}
		}
	} else {
		for i := 0; i < len(s); i++ {
			if s[i] >= 'a' && s[i] <= 'z' {
				s[i] = byte(int(s[i]) + (int('A') - int('a')))
			}
		}
	}

	println(string(s))

}

// ----------------------------- /* End of useful functions */ -------------------------------
