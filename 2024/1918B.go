// link: https://codeforces.com/contest/1918/problem/B B. Minimize Inversions
// time: 2024/6/12 21:28:43 https://github.com/funcdfs

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
type pair struct {
	x, y int
}

func solve(_case int) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)

	n := input[int]()
	c := make([]pair, n)
	for i := range c {
		c[i].x = input[int]()
	}
	for i := range c {
		c[i].y = input[int]()
	}
	sort.Slice(c, func(i, j int) bool {
		return c[i].x < c[j].x
	}) // 只有当 a[i] > a[j] && b[i] > b[j] 的时候，交换才会减少总数。
	// 所以不管排序 a 还是排序 b，总数的减少量是固定的。
	// 排序 a 会消除所有的 a[i] > a[j]： 包含只交换可以减少总数的位置 的方案
	// 排序 b 会消除所有的 b[i] > b[j]:  也包含只交换可以减少总数位置 的方案
	// [1, 2] [2, 1] 怎么换都一样 (这也是使用排序过程，多换的那一部分)
	// [2, 1] [2, 1] 总数少 2 （这是只交换可以减少总数位置的 那一部分） 排序等于这两部分的总和操作。
	// [1, 2] [1, 2] 不用换
	for i := range c {
		printx(c[i].x)
	}
	println()
	for i := range c {
		printx(c[i].y)
	}
	println()

}

// solve -------------------------------------------------------------

// #region main

func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	// preProcess()
	testCaseCnt := input[int]()
	for i := 1; i <= testCaseCnt; i++ {
		solve(i)
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
func println() {
	fmt.Fprint(_out, "\n")
}
func printx[T any](x ...T) {
	for i := range x {
		fmt.Fprint(_out, x[i], " ")
	}
}

// #endregion fastIO
