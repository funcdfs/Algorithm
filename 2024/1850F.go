// created: 2024/5/29 12:10:25 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1850/problem/F

package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strings"
)

// region solve
// --------------------------------------------------------------------------
func solve(_case int, _in *bufio.Reader, _out *bufio.Writer) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)
	n := 0
	fmt.Fscan(_in, &n)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(_in, &a[i])
	}

	cnt := make(map[int]int)
	for _, ai := range a {
		cnt[ai] += 1
	}
	ans := make([]int, n+1)
	for step := 1; step <= n; step++ {
		for i := step; i <= n; i += step {
			ans[i] += cnt[step]
		}
	}
	fmt.Fprintln(_out, Max(ans[1:]...))
}

// --------------------------------------------------------------------------
// endregion solve

func Max[T int | int64 | float32 | float64 | string](args ...T) T {
	res := args[0]
	for i := 1; i < len(args); i++ {
		if args[i] > res {
			res = args[i]
		}
	}
	return res
}

func preProcess() {

}

// region main
func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	preProcess()
	var testCaseCnt int
	fmt.Fscan(_in, &testCaseCnt)
	for i := 1; i <= testCaseCnt; i++ {
		solve(i, _in, _out)
	}
	leftData, _ := io.ReadAll(_in)
	if s := strings.TrimSpace(string(leftData)); s != "" {
		panic("!!!!!!!DATA INPUT ERROR!!!!!!! \n\n" + s + "\n")
	}
}

// endregion main
