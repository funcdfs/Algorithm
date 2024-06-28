// link: https://codeforces.com/contest/1497/problem/B B. M-arrays
// time: 2024/6/18 13:51:36 https://github.com/funcdfs

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

func solve(_case int) { // log.Println("# CASE: ", _case)

	n, m := input[int](), input[int]()
	a := inputSlice[int](n)
	hs := make(map[int]int)
	for i := range a {
		a[i] = a[i] % m
		hs[a[i]] += 1
	}
	ans := 0
	if _, ok := hs[0]; ok == true {
		ans += 1
	}
	for i := 1; i < m; i++ {
		if _, ok := hs[i]; ok == true {
			t := abs(hs[i] - hs[m-i])
			if t <= 1 {
				ans += 1
			} else {
				ans += t
			}
			delete(hs, m-i)
		}
	}
	println(ans)

}

func abs[T int | int64 | float32 | float64](x T) T {
	if x < T(0) {
		return -x
	}
	return x
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
