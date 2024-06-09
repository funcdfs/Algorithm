// created: 2024/6/5 19:13:51 author:  https://github.com/funcdfs
// problem: https://atcoder.jp/contests/abc301/tasks/abc301_a

package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// solve -------------------------------------------------------------

func solve() {
	
	_ = input[int]()
	
	constStr := input[string]()
	_ = []byte(constStr)
	
	cnt1 := strings.Count(constStr, "A")
	cnt2 := strings.Count(constStr, "T")
	if cnt1 == cnt2 {
		if constStr[len(constStr)- 1] == 'A' {
			print("T")
			return
		} else {
			print("A")
			return
		}
	} else {
		if cnt1 > cnt2 {
			print("A")
			return 
		} else {
			print("T")
			return
		}
	}
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
