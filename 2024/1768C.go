// created: 2024/6/3 22:01:18 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1768/problem/C

package main

import (
	"bufio"
	"fmt"
	"os"
)

// region solve ----------------------------------------------------
func solve(_case int, _in *bufio.Reader, _out *bufio.Writer) {
	// fmt.Fprintln(os.Stderr, "# CASE: ", _case)
	n := 0
	fmt.Fscan(_in, &n)
	a := make([]int, n)
	for i := range a {
		fmt.Fscan(_in, &a[i])
	}

	// find two permutation p and q, max(pi, qi) = ai
	cnt := make(map[int]int, 0)
	for i := range a {
		cnt[a[i]] += 1
		if cnt[a[i]] > 2 {
			fmt.Fprintln(_out, "NO")
			return
		}
	}

}

// endregion solve --------------------------------------------------

func main() {
	_in := bufio.NewReader(os.Stdin)
	_out := bufio.NewWriter(os.Stdout)
	defer _out.Flush()
	// preProcess()
	var testCaseCnt int
	fmt.Fscan(_in, &testCaseCnt)
	for i := 1; i <= testCaseCnt; i++ {
		solve(i, _in, _out)
	}
}

/*

 */
