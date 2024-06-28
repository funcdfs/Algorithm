// link: https://www.luogu.com.cn/problem/CF9A Die Roll
// time: 2024/6/15 12:46:32 https://github.com/funcdfs

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

	Y, W := input[int](), input[int]()
	val := max(Y, W)

	cnt := 6 - val + 1
	x := Gcd(cnt, 6)
	printx(cnt / x)
	printx("/")
	printx(6 / x)

}

func Gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return Gcd(b, a%b)
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
		fmt.Fprint(_out, x[i], "")
	}
}

// #endregion io
