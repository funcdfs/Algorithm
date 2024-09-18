// link: https://codeforces.com/contest/1807/problem/B B. Grab the Candies
// time: 2024/9/16 16:40:40 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
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

	n := input[int]()
	a := inputSlice[int](n)

	final := make([]int, 0, n)
	part2 := make([]int, 0, n)
	sumEven, sumOdd := 0, 0
	for i := range a {
		if a[i]%2 == 0 {
			final = append(final, a[i])
			sumEven += a[i]
		} else {
			part2 = append(part2, a[i])
			sumOdd += a[i]
		}
	}
	final = append(final, part2...)

	if sumEven > sumOdd {
		println("YES")
	} else {
		println("NO")
	}

}

// ----------------------------- /* End of useful functions */ -------------------------------
