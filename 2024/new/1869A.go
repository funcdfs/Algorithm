// link: https://codeforces.com/contest/1869/problem/A A. Make It Zero
// time: 2024/6/17 15:30:29 https://github.com/funcdfs

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
	_ = inputSlice[int](n)

	// 1111 replace one: 1111 -> 0
	// make even length to zero need two same step

	if n%2 > 0 {
		println(4)
		println(1, n-1)
		println(1, n-1)
		println(n-1, n)
		println(n-1, n)
	} else {
		println(2)
		println(1, n)
		println(1, n)
	}
}

// 如果把所有数都一起异或起来。那么对于每一位来说，如果这一位上本来有奇数个1，那么最后所有数在这一位都会是1。否则就都是0。
// 那么如果n是偶数，最坏的情况也就是第一次把所有数的某一位全部变成1，然后再全部异或依次变成0。
// 如果n是奇数也是类似的。第一步也是把所有数的某一位都变成1。然后把前n-1个数变成0。接着再把最后两个数全变成1。最后把最后两个数变成0。

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
