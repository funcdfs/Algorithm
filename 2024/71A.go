// link: https://codeforces.com/contest/71/problem/A A. Way Too Long Words
// time: 2024/9/10 13:11:40 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var _in, _out = new(bufio.Reader), new(bufio.Writer)

func _print_config[T any](sep, end string, arr ...T) {
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
func print[T any](arr ...T)   { _print_config(" ", " ", arr...) }
func println[T any](arr ...T) { _print_config(" ", "\n", arr...) }

// #endregion main

// ----------------------------- /* Start of useful functions */ -----------------------------
func solve(_case int) {

	s := input[[]byte]()

	if len(s) > 10 {
		x := len(s) - 2
		ans := make([]byte, 0)
		ans = append(ans, s[0])
		ans = append(ans, []byte(strconv.FormatInt(int64(x), 10))...)
		ans = append(ans, s[len(s)-1])
		println(string(ans))
	} else {
		println(string(s))
	}

}

// ----------------------------- /* End of useful functions */ -------------------------------
