// link: https://codeforces.com/contest/1850/problem/C C. Word on the Paper
// time: 2024/9/15 20:27:02 https://github.com/funcdfs

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

	grid := make([][]byte, 8)
	ans := make([]byte, 0, 8)

	for i := range grid {
		grid[i] = input[[]byte]()
	}

	for i := range grid {
		for idx := range grid[i] {
			if grid[i][idx] != '.' {
				for j := i; j < 8 && grid[j][idx] != '.'; j++ {
					ans = append(ans, grid[j][idx])
				}
				goto final
			}
		}
	}

	final:
	println(string(ans))

}

// ----------------------------- /* End of useful functions */ -------------------------------
