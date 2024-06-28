// link: https://codeforces.com/contest/1838/problem/A A. Blackboard List
// time: 2024/6/15 12:11:08 https://github.com/funcdfs

// #region import
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

// #endregion import

// solve -------------------------------------------------------------

func solve(_case int) {
	// log.Println("# CASE: ", _case)
	n := input[int]()
	a := inputSlice[int](n)

	// every case choose any number. wirte down the difference on the board
	// output on of the two initial numbers on the blackboard

	for i := range a {
		if a[i] < 0 {
			print(a[i])
			return // any negative integers must have been one of the original two numbers
		}
	}
	print(max(a...))
	return // if a <= b: |a-b| = b-a <= b
}

func max[T int | int64 | float32 | float64](x ...T) T {
	var maxVal T 
	for _, v := range x {
		if v > maxVal {
			maxVal = v 
		}
	}
	return maxVal
}

// solve -------------------------------------------------------------

// #region main
func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	log.SetFlags(log.Lshortfile)
	defer _out.Flush()
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
}

// #endregion main

// #region io
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
			fmt.Fprint(_out, "\n")
		} else {
			fmt.Fprint(_out, " ")
		}
	}
}
func println() {
	fmt.Fprint(_out, "\n")
}
func printx[T any](x ...T) {
	for i := range x {
		fmt.Fprint(_out, x[i], " ")
	}
}

// #endregion io
