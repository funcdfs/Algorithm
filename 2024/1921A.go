// link: https://codeforces.com/contest/1921/problem/A A. Square
// time: 2024/9/16 20:00:45 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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
type pair struct {
	x, y int
}

func solve(_case int) {

	points := make([]pair, 4)
	for i := range points {
		points[i].x, points[i].y = input[int](), input[int]()
	}
	sort.Slice(points, func(i, j int) bool {
		return points[i].y < points[j].y
	})

	a, b := points[2], points[3]
	edgeLen := abs(a.x - b.x)
	println(edgeLen * edgeLen)

}

func abs[T int | int64 | float32 | float64](x T) T {
	if x < T(0) {
		return -x
	}
	return x
}

// ----------------------------- /* End of useful functions */ -------------------------------
