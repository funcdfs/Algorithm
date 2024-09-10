// #region main
package main

import (
	"bufio"
	"fmt"
	"os"
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
func print[T any](arr ...T)   { _print_config(" ", " ", arr...) }
func println[T any](arr ...T) { _print_config(" ", "\n", arr...) }

// #endregion main

// ----------------------------- /* Start of useful functions */ -----------------------------

func solve() {

	s1 := input[[]byte]()
	s2 := input[[]byte]()
	for i := 0; i < len(s1); i++ {
		if s1[i] >= 'A' && s1[i] <= 'Z' {
			s1[i] = byte(int(s1[i]) - (int('A') - int('a')))
		}
		if s2[i] >= 'A' && s2[i] <= 'Z' {
			s2[i] = byte(int(s2[i]) - (int('A') - int('a')))
		}
		if s1[i] < s2[i] {
			println(-1)
			return
		} else if s1[i] > s2[i] {
			println(1)
			return
		}
	}
	println(0)
}

// ----------------------------- /* End of useful functions */ -------------------------------
