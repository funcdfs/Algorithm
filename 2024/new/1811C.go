// LUOGU_RID: 162574021
// link: https://codeforces.com/contest/1811/problem/C C. Restore the Array
// time: 2024/6/19 19:59:32 https://github.com/funcdfs

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

	n := input[int]()
	b := inputSlice[int](n - 1)

	a := make([]int, n)
	a[0] = b[0]          // i == 1: a[i] = b[i]
	a[n-1] = b[len(b)-1] // i == n: a[i] = b[i - 1]

	for i := 2; i <= n-1; i++ { // i == 2
		idx := i - 1
		a[idx] = min(b[idx], b[idx-1]) // a[i] = min(b[i], b[i-1]) otherwise
	} // a[i]<b[i]==max(a[i], a[i+1]), a[i]<b[i-1]==max(a[i-1], a[i]) -> a[i]=min(b[i], b[i-1])
	println(a...)

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
