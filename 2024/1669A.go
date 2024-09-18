// link: https://codeforces.com/contest/1669/problem/A A. Division?
// time: 2024/9/16 17:57:36 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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

	s := input[[]byte]()
	num := 0
	if s[0] == '-' {
		num, _ = strconv.Atoi(string(s[1:len(s)]))
	} else {
		num, _ = strconv.Atoi(string(s[0:len(s)]))
	}

	if s[0] == '-' {
		println("Division 4")
	} else {
		if num <= 1399 {
			println("Division 4")
		} else if num >= 1400 && num <= 1599 {
			println("Division 3")
		} else if num >= 1600 && num <= 1899 {
			println("Division 2")
		} else if num >= 1900 {
			println("Division 1")
		}
	}

}

// ----------------------------- /* End of useful functions */ -------------------------------
