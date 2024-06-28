// #region import
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"sort"
)

// #endregion import

// solve -------------------------------------------------------------

func solve(_case int) {
	// log.Println("# CASE: ", _case)
	n := input[int]()
	a := inputSlice[int](n)

	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})

	for idxL, idxR, sumL, sumR := 1, n-1, int64(a[0]), int64(0); idxL < idxR; idxL, idxR = idxL+1, idxR-1 {
		sumL += int64(a[idxL])
		sumR += int64(a[idxR])
		if sumL < sumR {
			print("YES")
			return
		}
	}
	print("NO")
	return
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
