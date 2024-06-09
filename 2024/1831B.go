// created: 2024/6/8 15:08:23 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1831/problem/B

package main

import (
	"bufio"
	"fmt"
	"os"
)

// solve -------------------------------------------------------------

func solve(_case int) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)

	n := input[int]()
	a := inputSlice[int](n)
	b := inputSlice[int](n)

	cnta := make(map[int]int)
	cntb := make(map[int]int)
	fill := func(arr []int, hs map[int]int) {
		for i := 0; i < n; i++ {
			x := arr[i]
			idx := i
			for idx < len(arr) && arr[idx] == x {
				idx += 1
			}
			hs[x] = max(hs[x], idx-i)
			i = idx - 1
		}
	}

	fill(a, cnta)
	fill(b, cntb)

	ans := 0
	for k, v := range cnta {
		ans = max(ans, v)
		if val, ok := cntb[k]; ok == true {
			ans = max(ans, v+val)
		}
	}
	for k, v := range cntb {
		ans = max(ans, v)
		if val, ok := cnta[k]; ok == true {
			ans = max(ans, v+val)
		}
	}
	print(ans)
}

// solve -------------------------------------------------------------

func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	// preProcess()
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
}

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
