// created: 2024/6/8 23:45:18 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1614/problem/B

// #region import
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

// #endregion import

// solve -------------------------------------------------------------

func solve(_case int) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)
	n := input[int]()
	a := make([][2]int, n)
	for i := range a {
		a[i][0] = input[int]()
		a[i][1] = i + 1
	}
	sort.Slice(a, func(i, j int) bool {
		return a[i][0] > a[j][0]
	})
	x := make([]int, n+1)
	x[0] = 0
	ans, l, r := int64(0), -1, 1
	for i := 0; i < n; i++ {
		id := a[i][1]
		if r == -l {
			x[id] = l
			l -= 1
		} else {
			x[id] = r
			r += 1
		}
		ans += int64(abs(x[id])) * int64(a[i][0])
	}
	print(ans * 2)
	print(x...)
}
func abs(x int) int {
	if x < 0 {
		x = -x
	}
	return x
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
