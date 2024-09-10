// link: https://codeforces.com/contest/339/problem/A A. Helpful Maths
// time: 2024/9/10 13:58:56 https://github.com/funcdfs

// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var _in, _out = new(bufio.Reader), new(bufio.Writer)

func _print_config[T any](sep, end string, arr ...T) {
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
	solve()
}
func input[T any]() T { var value T; fmt.Fscan(_in, &value); return value }
func inputSlice[T any](size int) []T {
	data := make([]T, size)
	for idx := 0; idx < size; idx++ {
		data[idx] = input[T]()
	}
	return data
}
func print[T any](arr ...T) { _print_config("", "", arr...) }

// func print      [T any] (arr ...T)     { _print_config(" ", " ", arr...) }
func println[T any](arr ...T) { _print_config(" ", "\n", arr...) }

// #endregion main

// ----------------------------- /* Start of useful functions */ -----------------------------

func solve() {

	s := input[[]byte]()
	nums := make([]int, 0)

	for i := 0; i < len(s); i++ {
		idx := i
		for idx < len(s) && s[idx] != '+' {
			idx++
		}
		x, err := strconv.Atoi(string(s[i:idx]))
		if err != nil {
			println("convert error")
		}
		i = idx
		nums = append(nums, x)
	}
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	for i := 0; i < len(nums); i++ {
		print(nums[i])
		if i != len(nums)-1 {
			print("+")
		} else {
			print("\n")
		}
	}
}

// ----------------------------- /* End of useful functions */ -------------------------------
