// link: https://codeforces.com/contest/1907/problem/C C. Removal of Unattractive Pairs
// time: 2024/6/21 19:56:00 https://github.com/funcdfs

// #region import
package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
)

// #endregion import

// ---------------------------------------------------------------

func solve(_case int) { // log.Println("# CASE: ", _case)

	n := input[int]()
	s := input[[]byte]()

	cnt := make(map[byte]int)
	for i := range s {
		cnt[s[i]] += 1
	}
	maxFreq := cnt[s[0]]
	maxVal := s[0]
	for k, v := range cnt {
		if v > maxFreq {
			maxFreq = v
			maxVal = k
		}
	}

	if n-maxFreq >= maxFreq {
		println(n % 2)
	} else {
		sum := int64(0)
		for k, v := range cnt {
			if k == maxVal {
				continue
			}
			sum += int64(v)
		}
		println(int64(n) - int64(2)*sum)
	}

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
