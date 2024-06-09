// created: 2024/5/31 15:26:22 author:  https://github.com/funcdfs 
// problem: https://codeforces.com/contest/1932/problem/A


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
	s := []byte{}
	fmt.Fscan(_in, &s) 
	// fmt.Fprintln(os.Stderr, s) 
	trap := make([]bool, n)
	for i := range s {
		if s[i] == '*' {
			trap[i] = true
		}
	}
	f := make([]int, n + 1)
	for i := 1 ; i< =n; i++ {
		if s[i - 1] == '*' {
			
		}
	}
}

// --------------------------------------------------------------------------
// endregion solve

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
