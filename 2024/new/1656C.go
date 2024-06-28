// link: https://codeforces.com/contest/1656/problem/C C. Make Equal With Mod
// time: 2024/6/25 17:28:32 https://github.com/funcdfs

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

// ---------------------------------------------------------------

func solve(_case int) { // log.Println("# CASE: ", _case)

	n := input[int]()
	a := inputSlice[int](n)

	cnt := 0
	for i := range a {
		if a[i] == 1 {
			cnt += 1
		}
	}
	if cnt == 0 {
		println("YES")
		return
	} else {
		hs := make(map[int]int, len(a))
		for i := range a {
			hs[a[i]] += 1
		}
		for i := range a {
			if _, ok := hs[a[i]-1]; ok == true {
				println("NO")
				return
			}
			if _, ok := hs[a[i]+1]; ok == true {
				println("NO")
				return
			}
		}
		println("YES")
	}

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
