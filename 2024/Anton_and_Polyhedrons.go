// link: https://www.luogu.com.cn/problem/CF785A Anton and Polyhedrons
// time: 2024/9/29 18:26:19 https://github.com/funcdfs

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

	sum := int64(0)
	n := input[int]()
	hs := make(map[string]int)
	hs["Tetrahedron"] = 4
	hs["Cube"] = 6
	hs["Octahedron"] = 8
	hs["Dodecahedron"] = 12
	hs["Icosahedron"] = 20
	for _ = range n {
		s := input[[]byte]()
		sum += int64(hs[string(s)])
	}

	println(sum)

}

// ----------------------------- /* End of useful functions */ -------------------------------
