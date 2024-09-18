// link: https://codeforces.com/contest/1294/problem/A A. Collecting Coins
// time: 2024/9/16 18:09:49 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
)

var _in, _out = new(bufio.Reader), new(bufio.Writer)

func _github_funcdfs[T any](sep, end string, arr ...T) {
	for idx := range arr {
		fmt.Fprint(_out, arr[idx])
		if idx == len(arr)-1 {
			fmt.Fprint(_out, end)
		} else {
			fmt.Fprint(_out, sep)
		}
	}
}
func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
}
func input[T any]() T { var value T; fmt.Fscan(_in, &value); return value }
func inputSlice[T any](size int) []T {
	data := make([]T, size)
	for idx := 0; idx < size; idx++ {
		data[idx] = input[T]()
	}
	return data
}
func print[T any](arr ...T)   { _github_funcdfs("", "", arr...) }
func println[T any](arr ...T) { _github_funcdfs(" ", "\n", arr...) }

// #endregion main

// ----------------------------- /* Start of useful functions */ -----------------------------
func solve(_case int) {

	ok := true 
	a, b, c, n := input[int](), input[int](), input[int](), input[int]()
	
	minCost := 0
	x := []int{a, b, c}
	maxVal := slices.Max(x)
	for i := range x {
		minCost += maxVal - x[i]
	}
	if n < minCost {
		ok = false
		goto final
	} else {
		if n == minCost {
			goto final
		} else {
			diff := n - minCost
			if diff % 3 == 0 {
				ok = true
				goto final
			} else {
				ok = false
				goto final
			}
		}
	}


	final:
	if ok {
		println("YES")
	} else {
		println("NO") 
	}

}

// ----------------------------- /* End of useful functions */ -------------------------------
