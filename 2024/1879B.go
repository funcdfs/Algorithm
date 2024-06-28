// link: https://codeforces.com/contest/1879/problem/B B. Chips on the Board
// time: 2024/6/15 13:13:18 https://github.com/funcdfs

// #region import
package main

import (
	"bufio"
	"fmt"
	"log"
	"math"
	"os"
)

// #endregion import

// solve -------------------------------------------------------------

func solve(_case int) {
	// log.Println("# CASE: ", _case)

	n := input[int]()
	a := inputSlice[int](n)
	b := inputSlice[int](n)

	// cost(i, j) == a[i]+b[j]
	minA, minB := math.MaxInt32, math.MaxInt32
	sumA, sumB := 0, 0

	for i := range a {
		sumA += a[i]
		minA = min(minA, a[i])
	}
	for i := range b {
		sumB += b[i]
		minB = min(minB, b[i])
	}
	x := minA*n + sumB // a[min]b[i]
	y := minB*n + sumA // a[i]b[min]
	print(min(x, y))
}

// 如果放置多于 n 个，那么可以删到 n 个，使得总和更小
// 如果放置少于 n 个，那么不可以完全覆盖整个棋盘。

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
