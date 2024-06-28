// link: https://codeforces.com/contest/1694/problem/B B. Paranoid String
// time: 2024/6/25 17:40:08 https://github.com/funcdfs

package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

// ---------------------------------------------------------------

func solve(_case int) { // log.Println("# CASE: ", _case)

	n := input[int]()
	s := input[[]byte]()
	// 01->1  10->0  cnt of len( substr(s) ) == 1
	// 不断地删除左边的字符，右边的不可撼动
	// 当子串最后两个不一样的时候 00000010 都可以

	ans := int64(0)
	ans += 1 // 0 position len(s[0]) == 1 
	for i := 1; i < n; i++ {
		if s[i] != s[i-1] {
			ans += int64(i+1)
		} else {
			ans += 1
		}
	}
	println(ans)
}

// ---------------------------------------------------------------

// #region fastIO

var _in, _out = new(bufio.Reader), new(bufio.Writer)

func main() {
	_in = bufio.NewReader(os.Stdin)
	_out = bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	log.SetFlags(log.Lshortfile)
	testCaseCnt := input[int]()
	for i := 0; i < testCaseCnt; i++ {
		solve(i + 1)
	}
}
func input[T any]() T { var value T; fmt.Fscan(_in, &value); return value }
func inputSlice[T any](length int) []T {
	data := make([]T, length)
	for i := 0; i < length; i++ {
		data[i] = input[T]()
	}
	return data
}
func print[T any](sep, end string, x ...T) {
	for i := range x {
		fmt.Fprint(_out, x[i])
		if i == len(x)-1 {
			fmt.Fprint(_out, end)
		} else {
			fmt.Fprint(_out, sep)
		}
	}
}
func println[T any](x ...T) { print(" ", "\n", x...) }

// #endregion fastIO
