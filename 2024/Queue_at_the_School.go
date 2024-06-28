// link: https://www.luogu.com.cn/problem/CF266B Queue at the School
// time: 2024/6/15 13:04:38 https://github.com/funcdfs

// #region import
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

// #endregion import

// solve -------------------------------------------------------------

func solve() {

	n, t := input[int](), input[int]()
	constStr := input[string]()
	s := []byte(constStr)

	for time := 1; time <= t; time++ {
		for i := 0; i+1 < n; {
			if s[i] == 'B' && s[i+1] == 'G' {
				s[i], s[i+1] = s[i+1], s[i]
				i += 2
			} else {
				i += 1
			}
		}
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
	solve()
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
