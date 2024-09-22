// link: https://codeforces.com/contest/1921/problem/C C. Sending Messages
// time: 2024/9/22 02:23:08 https://github.com/funcdfs

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

	messageCnt, powerTotal, oneHourPower, restartPower := input[int](), input[int](), input[int](), input[int]()

	message := inputSlice[int](messageCnt)

	needPower := int64(0)
	last := 0
	for i := 0; i < messageCnt; i++ {
		a := int64(1) * int64(restartPower)
		b := int64(message[i]-last) * int64(oneHourPower)
		needPower += min(a, b)
		last = message[i]
	}

	if needPower < int64(powerTotal) {
		println("YES")
	} else {
		println("NO")
	}
}

func min[T int | int64 | float32 | float64](x ...T) T {
	minVal := x[0]
	for _, v := range x {
		if v < minVal {
			minVal = v
		}
	}
	return minVal
}

// ----------------------------- /* End of useful functions */ -------------------------------
