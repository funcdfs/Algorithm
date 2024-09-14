// link: https://codeforces.com/contest/41/problem/A A. Translation
// time: 2024/9/14 10:53:59 https://github.com/funcdfs

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
func print[T any](arr ...T)   { _github_funcdfs("", "", arr...) }
func println[T any](arr ...T) { _github_funcdfs(" ", "\n", arr...) }

// #endregion main

// ----------------------------- /* Start of useful functions */ -----------------------------

func solve() {

	original := input[[]byte]()
	translation := input[[]byte]()

	slices.Reverse[[]byte](translation)

	ok := true
	if len(original) != len(translation) {
		ok = false
		goto final
	}
	for i := range original {
		if translation[i] != original[i] {
			ok = false
			goto final
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
