// created: 2024/6/5 18:10:24 author:  https://github.com/funcdfs
// problem: https://atcoder.jp/contests/abc351/tasks/abc351_b

package main

import (
	"bufio"
	"fmt"
	"os"
)

// solve -------------------------------------------------------------

func solve() {

	n := input[int]()
	g1, g2 := make([]string, n), make([]string, n)
	for i := range g1 {
		g1[i] = input[string]()
	}
	for i := range g2 {
		g2[i] = input[string]()
	}
	for x := 0; x < n; x++ {
		for y := 0; y < n; y++ {
			if g1[x][y] != g2[x][y] {
				print(x+1, y+1)
				return
			}
		}
	}
	return
}

// solve -------------------------------------------------------------

func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	// preProcess()
	solve()
}

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
			fmt.Fprintln(_out)
		} else {
			fmt.Fprint(_out, " ")
		}
	}
}
