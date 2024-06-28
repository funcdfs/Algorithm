// link: https://codeforces.com/contest/1933/problem/D D. Turtle Tenacity: Continual Mods
// time: 2024/6/25 22:21:39 https://github.com/funcdfs

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"slices"
)


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


// ---------------------------------------------------------------

func solve(_case int) { // log.Println("# CASE: ", _case)

	n := input[int]()
	a := inputSlice[int](n)

	check := func() bool {
		slices.Sort(a)
		if a[0] < a[1] {
			return true
		}
		for i := range a {
			if a[i]%a[0] != 0 {
				return true
			}
		}
		return false
	}
	if check() == true {
		println("YES")
	} else {
		println("NO")
	}

}

// ---------------------------------------------------------------