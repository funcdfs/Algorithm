// created: 2024/6/3 12:30:48 author:  https://github.com/funcdfs
// problem: https://codeforces.com/contest/1772/problem/D


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

