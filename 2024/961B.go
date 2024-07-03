// link: https://codeforces.com/contest/961/problem/B B. Lecture Sleep
// time: 2024/7/1 13:47:17 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

var _in, _out = new(bufio.Reader), new(bufio.Writer)

func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	log.SetFlags(log.Lshortfile)
	solve()
}
func input[T any]() T       { var value T; fmt.Fscan(_in, &value); return value }
func println[T any](x ...T) { print(" ", "\n", x...) }
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

// #endregion main

// solve -------------------------------------------------------------

func solve() {

	n, k := input[int](), input[int]()
	a := inputSlice[int](n)
	t := inputSlice[int](n)
	a, t = append([]int{0}, a...), append([]int{0}, t...)

	sum := int64(0)
	for i := range a {
		sum += int64(a[i] * t[i])
	}
	s := make([]int64, n+1)
	for i := 1; i <= n; i++ {
		s[i] = s[i-1] + int64(a[i]*(1-t[i]))
	}
	ans := int64(0)
	for i := 0; i+k <= n; i++ {
		ans = max(ans, s[i+k]-s[i])
	}
	println(ans + sum)
}

// solve -------------------------------------------------------------
