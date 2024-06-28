// link: https://codeforces.com/contest/1512/problem/C C. A-B Palindrome
// time: 2024/6/16 16:57:08 https://github.com/funcdfs

// #region import
package main

import (
	"bufio"
	"bytes"
	"fmt"
	"log"
	"os"
)

// #endregion import

// solve -------------------------------------------------------------

func solve(_case int) {
	// log.Println("# CASE: ", _case)

	a, b := input[int](), input[int]()
	s := input[[]byte]()
	n := len(s)

	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		if s[i] != '?' || s[j] != '?' {
			if s[i] == '?' {
				s[i] = s[j]
			} else if s[j] == '?' {
				s[j] = s[i]
			} else if s[i] != s[j] {
				print(-1)
				return
			}
		}
	}
	cnt0, cnt1 := bytes.Count(s, []byte{'0'}), bytes.Count(s, []byte{'1'})
	if cnt0 > a || cnt1 > b {
		print(-1)
		return
	}

	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		if s[i] == '?' {
			if a-2 >= cnt0 {
				s[i], s[j] = '0', '0'
				cnt0 += 2
			} else if b-2 >= cnt1 {
				s[i], s[j] = '1', '1'
				cnt1 += 2
			} else {
				print(-1)
				return
			}
		}
	}
	if n%2 > 0 && s[n/2] == '?' {
		if a-1 >= cnt0 {
			s[n/2] = '0'
			cnt0 += 1
		} else if b-1 >= cnt1 {
			s[n/2] = '1'
			cnt1 += 1
		} else {
			print(-1)
			return
		}
	}
	if cnt0 != a || cnt1 != b {
		print(-1)
		return
	}
	print(string(s))
}

// solve -------------------------------------------------------------

// #region main
func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	log.SetFlags(log.Lshortfile)
	defer _out.Flush()
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
}

// #endregion main

// #region io
var _in *bufio.Reader
var _out *bufio.Writer

func input[T any]() T {
	var value T
	fmt.Fscan(_in, &value)
	return value
}
func inputSlice[T any](length int) []T {
	data := make([]T, length)
	for i := 0; i < length; i++ {
		data[i] = input[T]()
	}
	return data
}
func print[T any](x ...T) {
	for i := range x {
		fmt.Fprint(_out, x[i])
		if i == len(x)-1 {
			fmt.Fprint(_out, "\n")
		} else {
			fmt.Fprint(_out, " ")
		}
	}
}
func println() {
	fmt.Fprint(_out, "\n")
}
func printx[T any](x ...T) {
	for i := range x {
		fmt.Fprint(_out, x[i], " ")
	}
}

// #endregion io
