// link: https://codeforces.com/contest/1743/problem/C C. Save the Magazines
// time: 2024/6/21 20:39:57 https://github.com/funcdfs

// #region import
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

// #endregion import

// ---------------------------------------------------------------

func solve(_case int) {

	n := input[int]()
	s := input[[]byte]()
	a := inputSlice[int](n)

	for i := 0; i < n-1; i++ {
		if s[i] == '0' && s[i+1] == '1' {
			j := i + 1
			minVal, minIdx := a[i], i
			for j < n && s[j] == '1' {
				if a[j] < minVal {
					minVal = a[j]
					minIdx = j
				}
				j += 1
			}
			for idx := i; idx < j; idx++ {
				if idx == minIdx {
					s[idx] = '0'
				} else {
					s[idx] = '1'
				}
			}
			i = j - 1
		}
	}
	sum := 0
	for i := range s {
		if s[i] == '1' {
			sum += a[i]
		}
	}
	println(sum)

}

// ---------------------------------------------------------------

// #region fastIO

var _in, _out = new(bufio.Reader), new(bufio.Writer)

func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	log.SetFlags(log.Lshortfile)
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
}
func input[T any]() T { var value T; fmt.Fscan(_in, &value); return value }
func inputSlice[T any](length int) []T {
	data := make([]T, length)
	for i := 0; i < length; i++ {
		data[i] = input[T]()
	}
	return data
}
func print[T any](sep, end string, x ...T) {
	for i := range x {
		fmt.Fprint(_out, x[i])
		if i == len(x)-1 {
			fmt.Fprint(_out, end)
		} else {
			fmt.Fprint(_out, sep)
		}
	}
}
func println[T any](x ...T) { print(" ", "\n", x...) }

// #endregion fastIO
