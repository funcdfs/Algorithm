// #region import
package main

import (
	"bufio"
	"fmt"
	"os"
)

// #endregion import

// solve -------------------------------------------------------------

func solve() {
	n := 10
	a := inputSlice[int](n)
	hs := make(map[int]int)
	for i := range a {
		if i == 0 {
			hs[Gcd(a[len(a)-1], a[0])] += 1
		} else {
			hs[Gcd(a[i], a[i-1])] += 1
		}
	}
	print(a)
	print(hs)
	a = inputSlice[int](n)
	hs = make(map[int]int)
	for i := range a {
		if i == 0 {
			hs[Gcd(a[len(a)-1], a[0])] += 1
		} else {
			hs[Gcd(a[i], a[i-1])] += 1
		}
	}
	print(a)
	print(hs)
}

func Gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return Gcd(b, a%b)
}

func preProcess() {

}

// solve -------------------------------------------------------------

// #region main
func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	preProcess()
	solve()
}

// #endregion main

// #region fastIO
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

// #endregion fastIO
