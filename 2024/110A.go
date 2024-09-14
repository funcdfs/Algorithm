// link: https://codeforces.com/contest/110/problem/A A. Nearly Lucky Number
// time: 2024/9/11 17:15:08 https://github.com/funcdfs

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

	cntLucky := 0
	for i := 0; i < len(s); i++ {
		if s[i] == '4' || s[i] == '7' {
			cntLucky += 1
		}
	}

	numCntLucky := 0
	num := []byte(strconv.Itoa(cntLucky))
	for i := 0; i < len(num); i++ {
		if num[i] == '4' || num[i] == '7' {
			numCntLucky += 1
		}
	}

	if cntLucky > 0 && numCntLucky == len(num) {
		println("YES")
	} else {
		println("NO")
	}
}

// ----------------------------- /* End of useful functions */ -------------------------------
