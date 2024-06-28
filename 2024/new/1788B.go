// link: https://codeforces.com/contest/1788/problem/B B. Sum of Two Numbers
// time: 2024/6/17 16:37:21 https://github.com/funcdfs

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
	c1, c2, cur := 0, 0, 1
	flag := true

	for n > 0 {
		d := n % 10
		n /= 10
		c1 = c1 + d/2*cur
		c2 = c2 + d/2*cur
		if d&1 == 1 {
			if flag == true {
				c1 += cur
			} else {
				c2 += cur
			}
			flag = !flag
		}
		cur *= 10
	}

	println(c1, c2)

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
