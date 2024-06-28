// link: https://codeforces.com/contest/1617/problem/B B. GCD Problem
// time: 2024/6/12 19:18:25 https://github.com/funcdfs

// #region import
package main

import (
	"bufio"
	"fmt"
	"os"
)

// #endregion import

// solve -------------------------------------------------------------

func solve(_case int) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)

	n := input[int]()
	// a + b + c == n
	// gcd(a, b) == c
	// find [a, b, c]
	/*
		a + b + gcd(a, b) == n
		if c == 1:
			gcd(a, b) == 1 -> (b == a - 1)
		相邻的两个数是互质的
		相邻的两个奇数是互质的
		if n % 2 == 0:
			ans: [n/2, n/2-1, 1]
		else:
	*/

	if n%2 == 0 {
		print(n/2, n/2-1, 1)
	} else {
		ans := n / 2
		if ans%2 == 0 { // 偶数，拆成两个相邻的奇数
			print(ans-1, ans+1, 1)
		} else { // 奇数，拆成两个相邻的奇数
			print(ans-2, ans+2, 1)
		}
	}

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
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
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
			fmt.Fprintln(_out)
		} else {
			fmt.Fprint(_out, " ")
		}
	}
}

// #endregion fastIO
