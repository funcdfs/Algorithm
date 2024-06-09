// created: 2024/5/31 11:52:51 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/702/problem/B

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

func solve(_in *bufio.Reader, _out *bufio.Writer) {
	n := 0
	fmt.Fscan(_in, &n)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(_in, &a[i])
	}
	hs := make(map[int]int)
	var ans int64 = 0
	for _, x := range a {
		for j := 1; j <= 30; j++ {
			t := (1 << j) - x
			if val, ok := hs[t]; ok == true {
				ans += int64(val)
			}
		}
		hs[x] += 1
	}
	fmt.Fprintln(_out, ans) 
}

func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()

	solve(_in, _out)
	leftData, _ := io.ReadAll(_in)
	if s := strings.TrimSpace(string(leftData)); s != "" {
		panic("!!!!!!!DATA INPUT ERROR!!!!!!! \n\n" + s + "\n")
	}
}
